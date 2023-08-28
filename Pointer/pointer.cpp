#include <iostream>

using namespace std;

int main()
{
    int a = 45;
    int *ptr = &a;

    *ptr = 46;

    cout << a;

    return 0;
}