#include <iostream>
using namespace std;

int main()
{
    int numbers[8] = {2, 5, 9, 7, 3, 6, 9, 8};
    int sum = 0;
    float avg = 0;

    for (int i = 0; i < 8; i++)
    {
        sum += numbers[i];
    }
    avg = sum / 8.0;

    cout << "Sum is: " << sum << endl;
    cout << "Average is: " << avg;

    return 0;
}
