#include <iostream>
using namespace std;

int m1, m2, m3; // marks

void setMarks()
{
A:
    cout << "Enter marks of subject 1: ";
    cin >> m1;
    if (m1 < 0 || m1 > 100)
    {
        cout << "\nInvalid Marks\n";
        goto A;
    }
B:
    cout << "\nEnter marks of subject 2: ";
    cin >> m2;
    if (m2 < 0 || m2 > 100)
    {
        cout << "\nInvalid Marks\n";
        goto B;
    }
C:
    cout << "\nEnter marks of subject 3: ";
    cin >> m3;
    if (m3 < 0 || m3 > 100)
    {
        cout << "\nInvalid Marks\n";
        goto C;
    }
}

void dispMarks()
{
    cout << "\nMarks in subject 1 = " << m1;
    cout << "\nMarks in subject 2 = " << m2;
    cout << "\nMarks in subject 3 = " << m3;
    cout << "\nAverage marks = " << (m1 + m2 + m3) / 3.0 << endl;
}

void Teacher()
{
    system("cls"); // clear screen
    cout << "\n-------------- FACULTY PORTAL ------------- \n";
    while (true)
    {
        char opt;
        cout << "\nChoose options: ";
        cout << "\n1. Enter student marks";
        cout << "\n2. Display student marks";
        cout << "\n0. EXIT\n";
        cin >> opt;
        switch (opt)
        {
        case '1':
            setMarks();
            break;
        case '2':
            dispMarks();
            break;
        case '0':
            system("cls"); // clear screen
            return;
        default:
            cout << "\nWRONG OPTION\n";
            break;
        }
    }
}

void Student()
{
    system("cls"); // clear screen
    cout << "\n-------------- STUDENT PORTAL ------------- \n";
    while (true)
    {
        char opt;
        cout << "\nChoose options: ";
        cout << "\n1. Display marks";
        cout << "\n0. EXIT\n";
        cin >> opt;
        switch (opt)
        {
        case '1':
            dispMarks();
            break;
        case '0':
            system("cls"); // clear screen
            return;
        default:
            cout << "\nWRONG OPTION\n";
            break;
        }
    }
}

int main()
{
    cout << "\n-------------- LOGIN ------------- \n";
    while (true)
    {
        char opt;
        cout << "\nChoose options: ";
        cout << "\n1. Login as Teacher";
        cout << "\n2. Login as Student";
        cout << "\n0. EXIT\n";
        cin >> opt;
        switch (opt)
        {
        case '1':
            Teacher();
            break;
        case '2':
            Student();
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