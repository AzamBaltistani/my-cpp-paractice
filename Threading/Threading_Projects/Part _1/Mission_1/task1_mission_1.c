#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // to handle threads

char array2D[100][100];      // a 100 x 100 2D array which holds alphabets
int alphabetCount[26] = {0}; // an array to store count of all 26 alphabets

// function to generate random alphabets
void randomAlphabetGenerator()
{
    // intializing our 2D array with random variables
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            array2D[i][j] = 'a' + (rand() % 26); // change 'a' to 'A' for CAPITAL alphabets
        }
    }
}

// function to count alphabets
void *countAlphabets(void *threadNumber)
{
    int *part = (int *)threadNumber; // the thread number is used as part number

    /*
    we need to split with five parts, like
    part 1 = 0 - 19
    part 2 = 20 - 39
    and so on
    */

    int partStart = *part * 20;   // e.g. if part = 2 then the part will start from 2x20 = 40
    int partEnd = partStart + 19; // e.g. thread 1 starts from 0 - 19

    for (int i = partStart; i <= partEnd; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            char currentAlphabet = array2D[i][j]; // the current alphabet which will be count
            // If we want to check the character either it is alphabet or not
            // we can use if(currentAlphabet >= 'a' && currentAlphabet <= 'z')
            // but in this case we are sure that the currentAlphabet is an alphabet

            alphabetCount[currentAlphabet - 'a']++;
            /* Explanation:
                if currentAlphabet is 'f' then the ASCII of 'f' is 102 and ASCII of 'a' is 97
                so, 102 - 97 = 5
                and the alphabet indexes are a=0, b=1, c=2, d=3, e=4, f=5
                hence, we increasing the count of 'f' by 1
            */
        }
    }

    pthread_exit(NULL); // end of thread
}

// function to print the all alphabet counts
void printCount()
{
    for (int i = 0; i < 26; i++)
    {
        printf("%c = %d\n", 'a' + i, alphabetCount[i]); // this will print small a to z with its count
        // to understand above line use ASCII, the ASCII of a=97, b=98, c=99 ...
    }
}

int main()
{
    randomAlphabetGenerator();

    pthread_t threadID[5]; // Thread IDs
    int threadNumber[5] = {0, 1, 2, 3, 4};
    // creating five threads
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threadID[i], NULL, countAlphabets, &threadNumber[i]);
    }

    // joining all threads to work all at once
    for (int j = 0; j < 5; j++)
    {
        pthread_join(threadID[j], NULL);
    }

    // printing the final result
    printCount();

    return 0;
}