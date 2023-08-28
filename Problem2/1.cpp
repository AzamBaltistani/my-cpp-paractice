#include <iostream>
using namespace std;

int main()
{
    float numbers[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter a number: ";
        cin >> numbers[i];
    }

    cout << "\nAll numbers: ";
    for (int j = 0; j < 10; j++)
    {
        cout << numbers[j] << ", ";
    }

    return 0;
}
