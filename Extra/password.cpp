#include <bits/stdc++.h>
using namespace std;
const string Password = "PPP";
void Login()
{
    system("cls");
    cout << "LOGIN SUCCESSFUL";
    return;
}

int main()
{
    cout << "\n-------------- LOGIN ------------- \n";
    while (true)
    {
        char opt;
        cout << "\nChoose options: ";
        cout << "\n1. Login";
        cout << "\n0. EXIT\n";
        cin >> opt;
        string password;
        switch (opt)
        {
        case '1':
            cout << "\nEnter password: ";
            cin >> password;
            if (password == Password)
                Login();
            else
                cout << "Wrong Password";
            break;
        case '0':
            system("cls"); // clear screen
            cout << "\nMusharaf Hussain\nRoll No: F21BIBBB1M06038";
            return 0;
        default:
            cout << "\nWRONG OPTION\n";
            break;
        }
    }

    return 0;
}