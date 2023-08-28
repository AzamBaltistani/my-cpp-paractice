#include <iostream>
#include <math.h>
#define M_PI
using namespace std;

int main()
{

    double radian = 0;
    cout << "Enter angle in radian: ";
    cin >> radian;

    double degree = (radian * 180) / M_PI;
    cout << "The angle in Degree is: " << degree;

    return 0;
}