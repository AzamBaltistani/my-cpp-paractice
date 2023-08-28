#include <iostream>
using namespace std;

int main()
{
    // google
    // 100% true
    string a = "oxyzkzyxs";
	int len = 0;
	
	while(a[len] != '\0') {
    	    len++;
    }


    int half = len / 2;

    len--;

    bool flag = true;

    for (int i = 0; i < half; i++)
    {
        if (a[i] != a[len])
        {
            flag = false;
            break;
        }
        len--;
    }

    if (flag == true)
    {
        cout << "String is palindrome";
    }
    else
    {
        cout << "String is not palindrome";
    }

    return 0;
}
