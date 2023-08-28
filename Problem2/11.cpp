#include <iostream>
#include <string>
using namespace std;

int main()
{
    // google
    string str1 = "abcdef";
    string str2 = "zxylef";
    float count = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == str2[i])
        {
            count++;
        }
    }

    float percent = count / str1.length() * 100;
    cout << "Strings are " << percent << " % equal";
    return 0;
}