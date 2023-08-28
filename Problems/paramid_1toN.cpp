#include <iostream>
using namespace std;

int main()
{
    int max = 0;

    cout << "Enter the max number for the pyramid: ";
    cin >> max;
    int number = 1;
    for (int row = 1; number <= max; ++row)
    {
        for (int col = 1; col <= row && number <= max; ++col)
        {
            cout << number++ << "   ";
        }
        cout << "\n";
    }

    return 0;
}