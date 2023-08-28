#include <iostream>

using namespace std;

int main()
{

    const double pi = 3.141592653589793238;

    double radian = 0;
    cout << "Enter angle in radian: ";
    cin >> radian;

    double degree = (radian * 180) / pi;
    cout << "The angle in Degree is: " << degree;

    return 0;
}