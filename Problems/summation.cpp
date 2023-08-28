#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter a: ";
    cin >> a;
    int sum = 0;
    for (int i = 1; i <= 20; i++)
    {
        sum += a * a;
    }

    cout << "Answer: " << sum << endl;

    return 0;
}