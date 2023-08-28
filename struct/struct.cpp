#include <iostream>

using namespace std;

struct rectangle
{
    int x;
    int y;

    int getArea()
    {
        return x * y;
    }

    int getParimeter()
    {
        return 2 * x + 2 * y;
    }
};

rectangle sumRectangle(rectangle r1, rectangle r2)
{
    rectangle temp;

    temp.x = r1.x + r2.x;
    temp.y = r1.y + r2.y;

    return temp;
}

int main()
{
    rectangle r1, r2;

    r1.x = 3;
    r1.y = 5;

    r2.x = 4;
    r2.y = 6;

    rectangle sum = sumRectangle(r1, r2);

    cout << "Area r1: " << r1.getArea() << endl;
    cout << "Area r2: " << r2.getArea() << endl;

    cout << "Area sum: " << sum.getArea() << endl;

    return 0;
}