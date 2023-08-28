#include <iostream>
#include <chrono>

void myFunction(int n)
{
    cout<<"\nFunction running\n";
}

int main()
{
    // Measure execution time for different input sizes
    for (int n = 10; n <= 100000; n *= 10)
    {
        auto start = std::chrono::high_resolution_clock::now();
        myFunction(n);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "Input size: " << n << ", Execution time: " << elapsed_time.count() << " microseconds\n";
    }

    return 0;
}

