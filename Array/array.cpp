#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string countries[5];

    cout << "Enter five countries: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> countries[i];
    }

    // Pakistan, India, Iran, China, America

    cout << "Countries starting with vowel: ";
    for (int j = 0; j < 5; j++)
    {
        if (countries[j][0] == 'A' || countries[j][0] == 'a' || countries[j][0] == 'E' || countries[j][0] == 'e' || countries[j][0] == 'I' || countries[j][0] == 'i' || countries[j][0] == 'O' || countries[j][0] == 'o' || countries[j][0] == 'U' || countries[j][0] == 'u')
        {
            cout << countries[j] << " ";
        }
    }
}