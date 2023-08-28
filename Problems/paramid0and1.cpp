#include <iostream>
using namespace std;

int main()
{
    int rows;

    cout << "Enter the number of rows for the pyramid: ";
    cin >> rows;

    for (int row = 1; row <= rows; ++row)
    {
        for (int col = 1; col <= row; ++col)
        {
            col % 2 != 0 ? cout << 1 : cout << 0;
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}