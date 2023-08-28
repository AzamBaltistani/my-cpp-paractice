//  QUEUE
#include <iostream>
using namespace std;

int queue[5];
int front = 0;
int rear = -1;

void push(int value)
{
    if (rear == 4)
    {
        cout << "Queue is full\n";
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}

void pop()
{
    if (front == rear + 1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        front++;
    }
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(10);
    push(12);
    push(14);

    pop();
    pop();

    display();

    return 0;
}
