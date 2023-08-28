/*
to develop a IUB online portal to facilitate students. You have been provided the following functional requirements of the system, which includes;
There should be a faculty portal and a student portal.
Faculty portal are being used by the Lecturers of IUB to enter student records. Lecturer A enters 3 subject marks in the faculty portal only. However, these marks can be seen by students in their own portal along with their marks average.
Additionally, based on the above depiction, use your knowledge of functions to implement such a system to satisfy customer requirements at any cost. Also, print your name, roll number at the end of program and display on the screen. */
#include <iostream>
using namespace std;

class Student
{
private:
    float marks1;
    float marks2;
    float marks3;
    float avgMarks;
    int rollNo;

public:
    Student(int rNo)
    {
        marks1 = 0;
        marks2 = 0;
        marks3 = 0;
        avgMarks = 0;
        rollNo = rNo;
    }
    int getRollNo() { return rollNo; }
    void setMarks1(float mark) { marks1 = mark; }
    void setMarks2(float mark) { marks2 = mark; }
    void setMarks3(float mark) { marks3 = mark; }
    float getAvgMarks() { return (marks1 + marks2 + marks3) / 3; }
    void displayStd()
    {
        cout << "\nRoll No: " << rollNo;
        cout << "\nMarks in Subject 1: " << marks1;
        cout << "\nMarks in Subject 2: " << marks2;
        cout << "\nMarks in Subject 3: " << marks3;
        cout << "\nAverage marks: " << avgMarks << endl;
    }
};

class Faculty
{
    string teacherName;
    int teacherID;

public:
    Faculty(string name, int ID)
    {
        teacherName = name;
        teacherID = ID;
    }
    void setMarks(Student std)
    {
        float temp;
        cout << "Enter marks of subject 1: ";
        cin >> temp;
        std.setMarks1(temp);
        cout << "Enter marks of subject 2: ";
        cin >> temp;
        std.setMarks2(temp);
        cout << "Enter marks of subject 3: ";
        cin >> temp;
        std.setMarks3(temp);
    }
};

int main()
{
    Student std1(4001);

    return 0;
}