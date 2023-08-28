#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "\nOriginal: " << s;
    s.push_back('y');
    cout << "\nAfter push: " << s;
    s.pop_back();
    cout << "\nAfter pop: " << s;

    return 0;
}