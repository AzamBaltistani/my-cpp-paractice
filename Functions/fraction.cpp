#include <iostream>
using namespace std;

double getFraction(double num)
{
    return num - int(num); // 165.544 - 165
}

int main()
{
    double number;
    cin >> number;

    cout << getFraction(number);

    return 0;
}