/**
 * @file 6_uint8tobits.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-11
 * 
 * @copyright Copyright (c) 2025
 * 
 * Make a program to read a number in the range of 0 and 255 
 * from the standard input and then print the binary form of the number to the output. 
 * While the enetered number is not in the range, 
 * the program shall ask for a new number. Use the bitwise operators!
 * 
 */

#include <cstdint>
#include <iostream>

void print_binary_uint8(uint8_t v)
{
    for (int i = 7; i >= 0; --i)
    {
        if (i == 3)
        {
            std::cout << ' ';
        }
        int bit = ((v >> i) & 1);
        std::cout << bit;
    }
    std::cout << '\n';
}

int main(void)
{
    uint8_t num{};
    int input = -1;
    while (input < 0 || input > 255)
    {
        std::cout << "Enter number (0-255): ";
        std::cin >> input;
        if (std::cin.bad())
        {
            input = -1;
        }
    }

    num = static_cast<uint8_t>(input);
    std::cout << "num: " << +num << '\n';
    print_binary_uint8(num);

    return 0;
}