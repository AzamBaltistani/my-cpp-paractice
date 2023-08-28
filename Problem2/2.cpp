#include <iostream>
using namespace std;

int main()
{
    float numbers[10];
    cout << "Enter ten numbers: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> numbers[i];
    }
    // 3 6 9 8 4 5 7 8 10 2
    int max = numbers[0];
    int min = numbers[0];

    for (int j = 0; j < 10; j++)
    {
        if (numbers[j] > max)
        {
            max = numbers[j];
        }

        if (numbers[j] < min)
        {
            min = numbers[j];
        }
    }

    cout << "Maximum is: " << max << endl;
    cout << "Minimum is: " << min << endl;
}