#include <bits/stdc++.h>
#include <set>
#include <iterator>
using namespace std;

int *greaterElement(int arr[], int n)
{

    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    for (int i = 0; i < n; i++)
    {

        auto a = s.find(arr[i]);
        a++;

        (a != s.end()) ? arr[i] = *a : arr[i] = -10000000;
    }

    return arr;
}

int main()
{
    int arr[] = {6, 3, 9, 8, 10, 2, 1, 15, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    greaterElement(arr, n);

    return 0;
}