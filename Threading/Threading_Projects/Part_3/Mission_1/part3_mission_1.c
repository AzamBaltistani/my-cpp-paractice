#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // for linux OS
// #include <Windows.h> // for Windows OS

#define GAS_MAX 100  // Maximum gas usage per second
#define ELEC_MAX 500 // Maximum electricity usage per second

double gas_usage = 0;  // Current gas usage per second
double elec_usage = 0; // Current electricity usage per second
double gas_total = 0;  // Accumulated gas usage
double elec_total = 0; // Accumulated electricity usage

pthread_mutex_t lock;

void *gas_reading(void *arg)
{
    while (1)
    {
        double gas = (double)rand() / RAND_MAX * GAS_MAX; // Generate random gas usage
        pthread_mutex_lock(&lock);                        // Lock shared data
        gas_usage = gas;
        gas_total += gas;
        pthread_mutex_unlock(&lock); // Unlock shared data
        // Sleep(1000);                 // Wait for 1s
        sleep(1); // Wait for 1s
    }
}

void *elec_reading(void *arg)
{
    while (1)
    {
        double elec = (double)rand() / RAND_MAX * ELEC_MAX; // Generate random electricity usage
        pthread_mutex_lock(&lock);                          // Lock shared data
        elec_usage = elec;
        elec_total += elec;
        pthread_mutex_unlock(&lock); // Unlock shared data
        // Sleep(1000);                 // Wait for 1s
        sleep(1); // Wait for 1s
    }
}

void *display_usage(void *arg)
{
    printf("\033[2J");   // clear entire screen
    printf("\033[1;1H"); // to send cursor on top

    while (1)
    {
        pthread_mutex_lock(&lock); // Lock shared data

        printf("\tGAS\n");
        printf("Usage:\t\t%.2f  m3/s\n", gas_usage);
        printf("Accumulated:\t%.2f  m3\n", gas_total);

        printf("\n---------------------------\n");

        printf("\tELECTRICITY\n");
        printf("Usage:\t\t%.2f  kW/s\n", elec_usage);
        printf("Accumulated:\t%.2f  kW\n", elec_total);

        pthread_mutex_unlock(&lock); // Unlock shared data
        // Sleep(1000);                 // Wait for 1s
        sleep(1); // Wait for 1s

        printf("\033[2J");   // clear entire screen
        printf("\033[1;1H"); // to send cursor on top
    }
}

int main()
{
    pthread_t gas_thread, elec_thread, display_thread;

    // Create mutex lock
    pthread_mutex_init(&lock, NULL);

    // Create tasks
    pthread_create(&gas_thread, NULL, gas_reading, NULL);
    pthread_create(&elec_thread, NULL, elec_reading, NULL);
    pthread_create(&display_thread, NULL, display_usage, NULL);

    // Join tasks
    pthread_join(gas_thread, NULL);
    pthread_join(elec_thread, NULL);
    pthread_join(display_thread, NULL);

    // Destroy mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}
