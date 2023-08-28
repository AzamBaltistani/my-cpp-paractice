/*
Create a struct called "Book" that has the following members:
title (string), author (string), and year (integer).
Write a C++ program that prompts the user to enter the details of five books,
stores them in an array of Book structs, and displays the details of the book
with the earliest year of publication.

*/

#include <iostream>

using namespace std;

struct books
{
    string title;
    string author;
    int year;
};

int main()
{
    books bookArray[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter title of the book: ";
        cin >> bookArray[i].title;

        cout << "Enter author of the book: ";
        cin >> bookArray[i].author;

        cout << "Enter publication year: ";
        cin >> bookArray[i].year;
    }
}