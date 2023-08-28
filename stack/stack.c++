// STACK
#include <iostream>
using namespace std;

int stack[5];
int top = -1;

void push(int value)
{
    if (top == 4)
    {
        cout << "Stack overflow! Stack is full\n";
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack underflow! Empty\n";
    }
    else
    {
        top--;
    }
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(5);
    push(10);
    push(7);
    push(6);
    push(9);

    pop();
    pop();
    pop();

    display();

    return 0;
}
