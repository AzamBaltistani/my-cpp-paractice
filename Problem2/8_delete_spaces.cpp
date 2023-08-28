#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
// Write a program to read a sentence & delete all the white spaces. Replace all �.� by �:�.
int main()
{
    string sen;

    cout << "Write a sentence: ";
    getline(cin, sen);

    for (int i = 0; i < sen.length(); i++)
    {
        if (sen[i] == ' ')
        {
            sen.erase(i, 1);
        }

        if (sen[i] == '.')
        {
            sen[i] = ':';
        }
    }

    cout << "\nYour sentence is: " << sen << endl;

    return 0;
}
