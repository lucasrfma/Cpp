/**
 * 
 * NEEDS TO COMPILE WITH "RELEASE MODE" 
 * Flag: -O3 or -Ofast
 * 
 * Ways to create threads in C++11
 * 1. Function Pointers
 * 2. Lambda Functions
 * 3. Functors
 * 4. Member Functions
 * 5. Static Member Functions
 * 
 * This program will add all odd numbers from 1 to 1900000000
 * as well as all even numbers in the same range.
 * (without using actually good maths, like just calculating the formula for a A.Progression)
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven2(ull start, ull end, ull& output)
{
    std::cout << "Find Even Started." << std::endl;
    output = 0;
    for(ull i = start; i <= end; ++i)
    {
        if(i%2 == 0)
        {
            output += i;
        }
    }
    std::cout << "Find Even Ended." << std::endl;
}
void findOdd2(ull start, ull end, ull& output)
{
    std::cout << "Find Odd Started." << std::endl;
    output = 0;
    for(ull i = start; i <= end; ++i)
    {
        if(i%2 == 1)
        {
            output += i;
        }
    }
    std::cout << "Find Odd Ended." << std::endl;
}
void findEven(ull start, ull end)
{
    std::cout << "Find Even Started." << std::endl;
    for(ull i = start; i <= end; ++i)
    {
        if(i%2 == 0)
        {
            EvenSum += i;
        }
    }
    std::cout << "Find Even Ended." << std::endl;
}
void findOdd(ull start, ull end)
{
    std::cout << "Find Odd Started." << std::endl;
    for(ull i = start; i <= end; ++i)
    {
        if(i%2 == 1)
        {
            OddSum += i;
        }
    }
    std::cout << "Find Odd Ended." << std::endl;
}

int main(int argc, char const *argv[])
{
    ull start = 0, end = 1900000000;
    ull OddSum = 0;
    ull EvenSum = 0;


    /**
     * Single Thread - Global
     */
    auto startTime = std::chrono::high_resolution_clock::now();

    findOdd(start,end);
    findEven(start,end);

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime-startTime);

    std::cout << "Single Thread - global:" << std::endl;
    std::cout << "OddSum: " << OddSum << std::endl;
    std::cout << "EvenSum: " << EvenSum << std::endl;

    std::cout << static_cast<double>(duration.count())/1000000 << " Seconds" << std::endl;

    /**
     * Dual Threads - Global
     */

    ::EvenSum = 0;
    ::OddSum = 0;

    startTime = std::chrono::high_resolution_clock::now();

    /**
     * Creating threads with function pointers
     */
    std::thread t3(findEven, start, end);
    std::thread t4(findOdd, start, end);

    t3.join();
    t4.join();

    stopTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime-startTime);

    std::cout << "Dual Threads - global:" << std::endl;
    std::cout << "OddSum: " << OddSum << std::endl;
    std::cout << "EvenSum: " << EvenSum << std::endl;

    std::cout << static_cast<double>(duration.count())/1000000 << " Seconds" << std::endl;

    return 0;
}
