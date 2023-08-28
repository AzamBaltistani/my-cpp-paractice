// Q5. The Student CD contains a partially written program named AreaRectangle.cpp. Your job is to complete the program. When it is complete, the program will ask the user to enter the width and length of a rectangle, and then display the rectangle’s area. The program calls the following functions, which have not been written:
// • getLength– This function should ask the user to enter the rectangle's length, and then return that value as a double.
// • getWidth- This function should ask the user to enter the rectangle's width, and then return that value as a double.
// • getArea– This function should accept the rectangle's length and width as arguments, and return the rectangle's area. The area is calculated by multiplying the length by the width.
// • displayData– This function should accept the rectangle's length, width, and area as arguments, and display them in an appropriate message on the screen.
#include <iostream>
using namespace std;
double getLength()
{
    double len;
    cout << "Enter lenght of rectangle: ";
    cin >> len;
    return len;
}
double getWidth()
{
    double width;
    cout << "Enter width of rectangle: ";
    cin >> width;
    return width;
}
double getArea(double length, double width)
{
    return length * width;
}
void displayData(double length, double width, double area)
{
    cout << "\nLength of Rectangle: " << length;
    cout << "\nWidth of Rectangle: " << width;
    cout << "\nArea of Rectangle: " << area;
}

int main()
{
    double length, width, area;
    length = getLength();
    width = getWidth();
    area = getArea(length, width);
    displayData(length, width, area);
    return 0;
}