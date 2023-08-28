#include <iostream>
#include <thread>
#include <Windows.h>

using namespace std;

// Function to be executed by the threads
void threadFunction(int value)
{
    cout << "\nHello " << value << "\n";
    Sleep(value);
}

int main()
{
    int argValue1 = 1; // Argument value for thread 1
    int argValue2 = 2; // Argument value for thread 2
    int argValue3 = 3; // Argument value for thread 3

    // Create three thread objects and pass the function and arguments
    thread thread1(threadFunction, argValue1);
    thread thread2(threadFunction, argValue2);
    thread thread3(threadFunction, argValue3);

    // Wait for all the threads to finish execution
    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
