#include <iostream>
using namespace std;

struct Courses
{
    string crs_name;
    int crs_creditHour;
};

struct Student
{
    string std_name;
    string std_gender;
    struct Courses crs;
};

struct Faculty
{
    string facMember_name;
    int facMember_salary;
    struct Courses crs;
};

struct Department
{
    string dep_name;
    struct Student students[10];
    struct Faculty faculty[5];
};

struct University
{
    string uni_name;
    struct Department department[2];
};

int main()
{
    University university;
    string string_value;
    int int_value;

    // part a
    cout << "\n---- Taking University information ---- \n";
    cout << "Enter university name: ";
    getline(cin, string_value);
    university.uni_name = string_value;

    cout << "\n----Taking Department information ---- \n";

    for (int i = 0; i < 2; i++)
    {

        cout << "Enter department " << i + 1 << " name: ";
        getline(cin, string_value); // old value will replace by new one
        university.department[i].dep_name = string_value;
        cout << endl;
    }

    cout << "\n----Taking Faculty Members information ---- \n";

    for (int f = 0; f < 2; f++) // faculty members of department 1 and 2
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter department " << f + 1 << ",faculty member " << i + 1 << " name: ";
            getline(cin, string_value);
            university.department[f].faculty[i].facMember_name = string_value;
            cout << "Enter department " << f + 1 << ",faculty member " << i + 1 << " salary: ";

            cin >> int_value;
            cin.ignore();
            university.department[f].faculty[i].facMember_salary = int_value;

            cout << "Enter department " << f + 1 << ",faculty member " << i + 1 << " course name: ";
            getline(cin, string_value);

            university.department[f].faculty[i].crs.crs_name = string_value;
            cout << "Enter department " << f + 1 << ",faculty member " << i + 1 << " course credit hour: ";

            cin >> int_value;
            cin.ignore();
            university.department[f].faculty[i].crs.crs_name = int_value;
            cout << endl;
        }
        cout << endl;
    }

    cout << "\n----Taking Students information ---- \n";

    for (int s = 0; s < 2; s++) // students of department 1 and 2
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Enter department " << s + 1 << ", student " << i + 1 << " name: ";
            getline(cin, string_value);
            university.department[s].students[i].std_name = string_value;

            cout << "Enter department " << s + 1 << ", student " << i + 1 << " gender (M/F or Other): ";
            getline(cin, string_value);
            university.department[s].students[i].std_gender = string_value;

            cout << "Enter department " << s + 1 << ", student " << i + 1 << " course name: ";
            getline(cin, string_value);
            university.department[s].students[i].crs.crs_name = string_value;

            cout << "Enter department " << s + 1 << ", student " << i + 1 << " course credit hour: ";

            cin >> int_value;
            cin.ignore();
            university.department[s].students[i].crs.crs_creditHour = int_value;
            cout << endl;
        }
        cout << endl;
    }

    // part b
    cout << "\n\nShowing hierarchical data \n\n";
    cout << "1. University\nUniversity Name: " << university.uni_name << endl;
    cout << "2. Department\n";
    for (int i = 0; i < 2; i++)
    {
        cout << "\n\tAll Faculty information of department " << i + 1 << endl;
        cout << "\tDepartment " << i + 1 << " name: " << university.department[i].dep_name;
        for (int f = 0; f < 5; f++)
        {
            cout << "\n\t\tMember " << f + 1 << " name: " << university.department[i].faculty[f].facMember_name << endl;
            cout << "\n\t\tMember " << f + 1 << " salary: " << university.department[i].faculty[f].facMember_name << endl;
            cout << "\t\t\tMember " << f + 1 << " course name: " << university.department[i].faculty[f].crs.crs_name << endl;
            cout << "\t\t\tMember " << f + 1 << " course credit hour: " << university.department[i].faculty[f].crs.crs_creditHour << endl;
            cout << endl;
        }
        cout << "\n\tAll Student information of department " << i + 1 << endl;
        for (int s = 0; s < 5; s++)
        {
            cout << "\t\tStudent " << s + 1 << " name: " << university.department[i].students[s].std_name << endl;
            cout << "\t\tStudent " << s + 1 << " gender: " << university.department[i].students[s].std_gender << endl;
            cout << "\t\t\tStudent " << s + 1 << " course name: " << university.department[i].students[s].crs.crs_name << endl;
            cout << "\t\t\tStudent " << s + 1 << " course credit hour: " << university.department[i].students[s].crs.crs_creditHour << endl;
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}