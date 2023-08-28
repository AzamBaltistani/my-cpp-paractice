#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <pthread.h>
#include <unistd.h>
// #include <Windows.h>
#include <time.h>
#include <stdbool.h>

// all price unit is dolor $
#define GAS_MAX 100  // Maximum gas usage per second
#define ELEC_MAX 500 // Maximum electricity usage per second

double gas_usage_perSec = 0;  // Current gas usage per second
double elec_usage_perSec = 0; // Current electricity usage per second
double gas_total_usage = 0;   // Accumulated gas usage
double elec_total_usage = 0;  // Accumulated electricity usage

double gas_rate_perSec = 1.2; // default price rate for one sec
double gas_price_perSec = 0;  // gas price for one sec
double gas_price_total = 0;   // accumulated gas price

double elec_rate_perSec = 0.7; // default price
double elec_price_oneSec = 0;  // accumulated electricity price
double elec_price_total = 0;   // accumulated electricity price

// daily price warning for gas, when it use 4 hours at its maximum consumption
double gas_price_warning = 100 * 3600 * 4;

// daily price warning for electricity, when it use 6 hours at its maximum consumption
double elec_price_warning = 500 * 3600 * 6;

short int displayLevel = 0;

pthread_mutex_t lock, readingLock;
pthread_cond_t cond_updateRate, cond_updateWarning, cond_RealTime, cond_updateDisplayLevel;
void *gas_reading(void *arg)
{
    while (1)
    {
        double gas = (double)rand() / RAND_MAX * GAS_MAX; // Generate random gas usage
        pthread_mutex_lock(&readingLock);                 // Lock shared data

        gas_usage_perSec = gas;
        gas_total_usage += gas;
        gas_price_perSec = gas_usage_perSec * gas_rate_perSec;
        gas_price_total += gas_rate_perSec * gas_price_perSec;
        pthread_mutex_unlock(&readingLock); // Unlock shared data
                                            // Sleep(1000);                 // Wait for 1s
        sleep(1);                           // Wait for 1s
    }
}

void *elec_reading(void *arg)
{
    while (1)
    {
        double elec = (double)rand() / RAND_MAX * ELEC_MAX; // Generate random electricity usage
        pthread_mutex_lock(&readingLock);                   // Lock shared data

        elec_usage_perSec = elec;
        elec_total_usage += elec;

        elec_price_oneSec = elec_usage_perSec * elec_rate_perSec;
        elec_price_total += elec_price_oneSec * elec_rate_perSec;
        pthread_mutex_unlock(&readingLock); // Unlock shared data
                                            // Sleep(1000);                 // Wait for 1s
        sleep(1);                           // Wait for 1s
    }
}

void showTimer()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf(" %02d:%02d:%02d ", tm->tm_hour, tm->tm_min, tm->tm_sec);

    fflush(stdout);
}

void *display_usage(void *arg)
{

    while (1)
    {
        pthread_mutex_lock(&readingLock); // Lock shared data

        printf("\033[2J"); // clear entire screen

        printf("\033[1;1H");

        if (displayLevel == 0 || displayLevel == 1)
        {
            printf("\tGAS\n");
            printf("Usage:\t\t%.2f  m3/s\n", gas_usage_perSec);
            printf("Accumulated:\t%.2f  m3\n", gas_total_usage);
        }
        // printf("\n---------------------\n");

        if (displayLevel == 0 || displayLevel == 2)
        {
            printf("\tELECTRICITY\n");
            printf("Usage:\t\t%.2f  kW/s\n", elec_usage_perSec);
            printf("Accumulated:\t%.2f  kW\n", elec_total_usage);
        }
        printf("\n---------------------\n");
        printf("TIME: ");
        showTimer();
        printf("\n---------------------\n");

        if (displayLevel == 0 || displayLevel == 1)
        {
            printf("Gas Cost: \t\t$ %.2lf   at rate: $ %.1lf ", gas_price_total, gas_rate_perSec);
            if (gas_price_total >= gas_price_warning)
            {
                printf("\t * Warning: Gas usage crossed the limit ( %.1lf)\n", gas_price_warning);
            }
            else if (gas_price_total >= gas_price_warning * 0.5) // starts from 50 %
            {
                printf("\t * Warning: Gas reached %.1lf percent to limit ( %.1lf) \n", (gas_price_total / gas_price_warning) * 100.0, gas_price_warning);
            }
        }

        if (displayLevel == 0 || displayLevel == 2)
        {
            printf("\nElectricity Cost: \t$ %.2lf    at rate: $ %.1lf ", elec_price_total, elec_rate_perSec);
            if (elec_price_total >= elec_price_warning)
            {
                printf("\t * Warning: Electricity usage crossed the limit ( %.1lf)\n", elec_price_warning);
            }
            else if (elec_price_total >= elec_price_warning * 0.5) // starts from 50 %
            {
                printf("\t * Warning: Electricity reached %.1lf percent to limit ( %.1lf)\n", (elec_price_total / elec_price_warning) * 100.0, elec_price_warning);
            }
        }
        printf("\n----------------");

        printf("\n\nChange Rate [0.5]:\tPress 'p' then press + or - , esc to exit");
        printf("\nChange Warning [1000]:\tPress 'w' then press + or - , esc to exit");
        printf("\nChange Display:\tPress 'a' again 'a' for next");

        pthread_mutex_unlock(&readingLock); // Unlock shared data
                                            // Sleep(1000);                 // Wait for 1s
        sleep(1);                           // Wait for 1s
    }
}

void *update_rates(void *arg)
{
    int trig = 0;
    while (1)
    {
        char c;
        pthread_mutex_lock(&lock);
        if (trig == 0)
        {
            pthread_cond_wait(&cond_updateRate, &lock);
            trig = 1;
        }

        c = getch();

        if (c == 43)
        {
            gas_rate_perSec += 0.5;
            elec_rate_perSec += 0.5;
        }
        else if (c == 45)
        {
            if (gas_rate_perSec >= 0.5)
                gas_rate_perSec -= 0.5;
            if (elec_rate_perSec >= 0.5)
                elec_rate_perSec -= 0.5;
        }

        if (c == 27)
        {
            pthread_cond_signal(&cond_RealTime);
            trig = 0;
        }

        pthread_mutex_unlock(&lock);
    }
}

void *update_warning(void *arg)
{
    int trig = 0;
    while (1)
    {
        char c;
        pthread_mutex_lock(&lock);
        if (trig == 0)
        {
            pthread_cond_wait(&cond_updateWarning, &lock);
            trig = 1;
        }

        c = getch();

        if (c == 43)
        {
            gas_price_warning += 1000;
            elec_price_warning += 1000;
        }
        else if (c == 45)
        {
            pthread_cond_wait(&cond_updateDisplayLevel, &lock);
            if (gas_price_warning >= 1000)
                gas_price_warning -= 1000;
            if (elec_price_warning >= 1000)
                elec_price_warning -= 1000;
        }

        if (c == 27)
        {
            pthread_cond_signal(&cond_RealTime);
            trig = 0;
        }

        pthread_mutex_unlock(&lock);
    }
}

void *updateDisplayLevel()
{
    while (1)
    {
        pthread_mutex_lock(&lock);

        pthread_cond_wait(&cond_updateDisplayLevel, &lock);
        if (displayLevel < 2)
            displayLevel++;
        else
            displayLevel = 0;
        pthread_cond_signal(&cond_RealTime);
        pthread_mutex_unlock(&lock);
    }
}

void setup()
{
    char c;
    printf("Want to setup - y/n (y to set new value & n to continue with default values): ");
    scanf("%c", &c);
    if (c != 121 && c != 89) // the ASCII of y and Y is 121 and 89 resp.
    {
        printf("\033[2J");   // clear entire screen
        printf("\033[1;1H"); // to send cursor on top
        return;
    }

    double tempValue;
    printf("Enter gas rate per second or 0 for default (in $): ");
    scanf("%lf", &tempValue);
    if (tempValue > 0)
    {
        gas_rate_perSec = tempValue;
    }

    printf("Enter electricity rate per second or 0 for default (in $): ");
    scanf("%lf", &tempValue);
    if (tempValue > 0)
    {
        elec_rate_perSec = tempValue;
    }

    printf("Enter gas warning level or 0 for default (in $): ");
    scanf("%lf", &tempValue);
    if (tempValue > 0)
    {
        gas_price_warning = tempValue;
    }

    printf("Enter electricity warning level or 0 for default (in $): ");
    scanf("%lf", &tempValue);
    if (tempValue > 0)
    {
        elec_price_warning = tempValue;
    }

    printf("\033[2J");   // clear entire screen
    printf("\033[1;1H"); // to send cursor on top
}

void *realTimeCommand()
{
    while (1)
    {
        char command;
        command = getch();
        pthread_mutex_lock(&lock);
        if (command == 80 || command == 112) // P or p
        {
            pthread_cond_signal(&cond_updateRate);
        }
        else if (command == 87 || command == 119) // W or w
        {
            pthread_cond_signal(&cond_updateWarning);
        }
        else if (command == 65 || command == 97) // A or a
        {
            pthread_cond_signal(&cond_updateDisplayLevel);
        }
        pthread_cond_wait(&cond_RealTime, &lock);
        pthread_mutex_unlock(&lock);
    }
}

int main()
{
    pthread_t gas_thread, elec_thread, display_thread;
    pthread_t realTimeCommand_thread;
    pthread_t update_thread, warning_thread, updateDisplayLevel_thread;

    // Create mutex lock
    pthread_mutex_init(&lock, NULL);
    pthread_mutex_init(&readingLock, NULL);
    pthread_cond_init(&cond_updateRate, NULL);
    pthread_cond_init(&cond_updateWarning, NULL);
    pthread_cond_init(&cond_RealTime, NULL);
    pthread_cond_init(&cond_updateDisplayLevel, NULL);
    setup();

    // Create tasks
    pthread_create(&display_thread, NULL, display_usage, NULL);
    pthread_create(&gas_thread, NULL, gas_reading, NULL);
    pthread_create(&elec_thread, NULL, elec_reading, NULL);
    pthread_create(&realTimeCommand_thread, NULL, realTimeCommand, NULL);
    pthread_create(&update_thread, NULL, update_rates, NULL);
    pthread_create(&warning_thread, NULL, update_warning, NULL);
    pthread_create(&updateDisplayLevel_thread, NULL, updateDisplayLevel, NULL);

    // Join tasks
    pthread_join(gas_thread, NULL);
    pthread_join(elec_thread, NULL);
    pthread_join(display_thread, NULL);
    pthread_join(realTimeCommand_thread, NULL);
    pthread_join(update_thread, NULL);
    pthread_join(warning_thread, NULL);
    pthread_join(updateDisplayLevel_thread, NULL);

    // Destroy mutex lock

    pthread_cond_destroy(&cond_updateRate);
    pthread_cond_destroy(&cond_updateWarning);
    pthread_cond_destroy(&cond_updateDisplayLevel);
    pthread_cond_destroy(&cond_RealTime);
    pthread_mutex_destroy(&lock);
    pthread_mutex_destroy(&readingLock);
    return 0;
}