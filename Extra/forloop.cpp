#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    int number;
    cin >> number;

    if (number < 0)
        cout << "Negative";
    else
        cout << "Positive";

    return 0;
}