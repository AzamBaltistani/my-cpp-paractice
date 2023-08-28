#include <pthread.h> // to handle threads
#include <errno.h>   // to handle errors
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // for linux OS
// #include <Windows.h> // for Windows OS

pthread_mutex_t mutexFillWater; // mutex for fill the water once at a time
pthread_cond_t condWaterLevel;  // condition variable to check water level

#define maxWaterLevel 100 // defining maximum water level
short int waterLevel = 0; // current water level
int winThreadId = -1;     // The winner thread ID, -1 means no has won yet

// function to add a randomly generated amount of water to the tank
void *fillWaterTank(void *arg)
{
    int currID = *(int *)arg;                               // current running thread
    while (waterLevel < maxWaterLevel && winThreadId == -1) // only runs when the tank is not full, and no thread is won yet
    {
        pthread_mutex_lock(&mutexFillWater); // initializing the mutex
        int amount = 1 + rand() % 9;         // generate random number between 0 to 9
        // check that either, by this amount, the tank will be full or not, also no thread is won yet
        if (amount + waterLevel >= maxWaterLevel && winThreadId == -1)
        {
            winThreadId = currID;                                                               // current thread ID will assign to winThreadId
            printf("Thread %d, cannot add: %d, Water Level: %d\n", currID, amount, waterLevel); // printing the tread ID that exceeded
            pthread_cond_signal(&condWaterLevel);                                               // signal to all waiting condition variables
        }
        else if (winThreadId == -1)
        {
            waterLevel += amount; // adding amount to tank
            // printing the message with thread ID and the added amount
            printf("Thread %d added: %d, Water Level: %d\n", currID, amount, waterLevel);
        }
        pthread_mutex_unlock(&mutexFillWater); // destroying the mutex
        // Sleep(1000);                           // for windows OS 1000 milis = 1s
        sleep(1); // for linux OS
    }
}

// function to check water level
void *checkWaterLevel(void *arg)
{
    pthread_mutex_lock(&mutexFillWater); // initializing the mutex

    while (1) // continuesly checking for tank to full
    {
        pthread_cond_wait(&condWaterLevel, &mutexFillWater); // waiting for signal

        // printing the Thread ID that has crossed the maximum water level first
        printf("Thread %d has exceeded the maximum water level. Current water level is %d\n", winThreadId, waterLevel);
        break; // stoping the loop
    }

    pthread_mutex_unlock(&mutexFillWater); // destroying the mutex
}

int main()
{
    pthread_mutex_init(&mutexFillWater, NULL); // initializing the mutex
    pthread_cond_init(&condWaterLevel, NULL);  // initializing the condition variable

    pthread_t thrID[4];           // thread IDs
    int thrNum[4] = {1, 2, 3, 4}; // thread numbers to identify which thread is working
    for (int i = 0; i < 3; i++)   // creating 3 threads to add water in the water tank
    {
        pthread_create(&thrID[i], NULL, fillWaterTank, &thrNum[i]);
    }

    // creating 1 thread to check water level, and wait to full the tank
    pthread_create(&thrID[3], NULL, checkWaterLevel, &thrNum[3]);

    for (int i = 0; i < 4; i++)
    {
        pthread_join(thrID[i], NULL); // running all four threads
    }

    pthread_cond_destroy(&condWaterLevel);  // destroying the condition variable
    pthread_mutex_destroy(&mutexFillWater); // destroying the mutex

    return 0; // program ended successfully
}