#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i = 0; i <= 50; i += 10)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << setw(2) << setfill('0') << i + j << " ";
        }
        cout << endl;
    }
    return 0;
}