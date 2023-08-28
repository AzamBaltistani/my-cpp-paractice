#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Armmmmy";

    str.erase(2, 3); // where , how many char

    cout << str << endl;

    string str2 = "abcgef";

    str2[3] = 'd';

    cout << str2;

    return 0;
}