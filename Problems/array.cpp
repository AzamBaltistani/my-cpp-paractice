#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {5, 10, 4, 3, 6};
    int sum = 0;
    int max = arr[0];

    cout << "The elements in the array are: ";
    for (int i = 0; i <= 5; i++)
    {
        cout << arr[i] << " ";
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    cout << "\nThe sum of element is: " << sum;
    cout << "\nThe maximum element is: " << max;
    cout << "\nThe array in reverse order is: ";
    for (int i = 4; i >= 0; i--)
        cout << arr[i] << " ";
    return 0;
}