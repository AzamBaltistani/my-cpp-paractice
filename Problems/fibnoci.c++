#include <iostream>

using namespace std;

int main()
{
    int num1 = 0, num2 = 1, nextNum = 0;

    cout << "Fibonacci Series up to 100: " << endl;

    for (int i = 0; num1 + num2 <= 100; i++)
    {
        if (i <= 1)
        {
            nextNum = i;
        }
        else
        {
            nextNum = num1 + num2;
            num1 = num2;
            num2 = nextNum;
        }

        cout << nextNum << " ";
    }
}