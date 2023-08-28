#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    char chr;
    char lastChr = 0;
    int chCount = 0;
    int woCount = 0;
    // Q7. Write a program to read a sentence and count the number of characters &words in that sentence.
    cout << "Enter a sentence: ";
    while (true)
    {

        chr = getche();

        if (chr == ' ')
        {

            if (chCount != 0 && lastChr != ' ')
            {
                woCount++;
            }
        }
        else if (chr == 13)
        {
            if (chCount != 0 && lastChr != ' ')
            {
                woCount++;
            }
            break;
        }
        else
        {
            chCount++;
        }

        lastChr = chr;
    }
    cout << endl;
    cout << "Characters in Sentence = " << chCount << endl;
    cout << "Words in Sentence = " << woCount;
    return 0;
}
