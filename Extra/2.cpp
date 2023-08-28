#include <iostream>
using namespace std;

class Animal
{
protected:
    void eat()
    {
        cout << "Eating... " << endl;
    }
};

class Dog : Animal
{
public:
    void bark()
    {
        cout << "Dog is barking .. ";
    }

    void eatAndBark()
    {
        eat();
        bark();
    }
};
int main()
{
    Animal ani;
    ani.eat();

    Dog dog1;
    dog1.bark();
    dog1.eat();
    dog1.eatAndBark();

    return 0;
}
