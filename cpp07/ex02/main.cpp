#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 7
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    std::cout << numbers << std::endl;
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    std::cout << numbers << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << &numbers << std::endl;
        std::cout << &tmp << std::endl;
        std::cout << tmp << std::endl;
        std::cout << &test << std::endl;
        std::cout << test << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}