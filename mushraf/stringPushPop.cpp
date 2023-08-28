#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";

    cout << "Before pop: ";
    cout << s;

    s.pop_back();
    cout << "\nAfter pop: ";
    cout << s;

    return 0;
}