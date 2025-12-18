/**
 * @file 11_string_case.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-16
 * 
 * @copyright Copyright (c) 2025
 * 
 * Make a program to read a std::string from a terminal and then convert
 * the uppercase letters to lowercase and vice versa and
 * in the end print the string to the standard output.
 * 
 * !! To change and print the string use only pointers. !!
 */

#include <iostream>
#include <string>

int main(void)
{
    std::string str;
    std::cout << "Enter string: ";
    std::cin >> str;

    for (auto& i : str)
    {
        if (i >= 'A' && i <= 'Z')
        {
            i += 32;
        }
        else if (i >= 'a' && i <= 'z')
        {
            i -= 32;
        }
    }

    std::cout << str << '\n';
    return 0;
}