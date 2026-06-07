#ifndef NUMUTILS_H
#define NUMUTILS_H

#include <random>
#include <limits>
#include <iostream>

inline short getRandNumBelow(short number)
{
    return static_cast<short>(std::rand() % number);
}

inline short getNumber()
{
    short number;
    std::cin >> number;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a valid number: ";
        std::cin >> number;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return number;
}

#endif
