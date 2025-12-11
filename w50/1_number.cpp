/**
 * @file 1_number.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief g++ -DNUMBER=8 1_number.cpp
 * @version 0.1
 * @date 2025-12-09
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef NUMBER
#error "NUMBER not defined"
#endif
#if NUMBER != 8 && NUMBER != 16
#error "NUMBER must be either 8 or 16"
#endif

#include <iostream>

int main(void)
{
    std::cout << NUMBER << '\n';
    return 0;
}