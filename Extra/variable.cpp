#include <iostream>
using namespace std;

int main()
{
    int intVar;
    string strVar;
    char charVar;
    double doubleVar;

    cout << "Enter values: ";
    cin >> intVar >> strVar >> charVar >> doubleVar;

    cout << "int is: " << intVar << endl;
    cout << "string is: " << strVar << endl;
    cout << "char is: " << charVar << endl;
    cout << "double is: " << doubleVar << endl;

    return 0;
}