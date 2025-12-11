/**
 * @file 7_reverse_str.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-11
 * 
 * @copyright Copyright (c) 2025
 * 
 * Make a program to get a string from the standard input, 
 * then print the string to the output in the reversed order.
 * Don’t use a standard function. Implement the algorithm by yourself.
 * 
 * For examaple:
 *  Enter a string: ABCDEF
 *  Reversed string: FEDCBA
 */

#include <iostream>
#include <string>

static std::string reverse_str(const std::string& str)
{
    std::string rev(str.size(), 0);
    for (auto c = str.crbegin(); c != str.crend(); ++c)
    {
        rev += *c;
    }
    return rev;
}

int main(void)
{
    std::string str;
    std::cout << "Enter string: ";
    std::cin >> str;

    std::string rev = reverse_str(str);
    std::cout << rev << '\n';

    return 0;
}