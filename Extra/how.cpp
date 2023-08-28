#include <iostream>
using namespace std;

int main()
{
    int marks;
    int b;

    cin >> marks;

    if (marks > 100 || marks < 0)
    {
        cout << "Wrong Entry";
    }
    else if (marks >= 80)
    {
        cout << "Grade A+";
    }
    else if (marks >= 70)
    {
        cout << "Grade A";
    }
    else if (marks >= 60)
    {
        cout << "Grade B";
    }
    else if (marks >= 50)
    {
        cout << "Grade C";
    }
    else
    {
        cout << "Fail";
    }

    return 0;
}