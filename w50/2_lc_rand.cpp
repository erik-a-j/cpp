/**
 * @file 2_lc_rand.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief g++ 2_lc_rand.cpp
 * @version 0.1
 * @date 2025-12-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout, std::cin;

int main(void)
{
    char c;
    cout << "Enter char: ";
    cin >> c;
    if (cin.good())
    {
        if (c >= 'a' && c <= 'z')
        {
            c -= 'a' - 'A';
        }
        cout << "char: " << c << '\n';
    }

    std::srand(std::time(nullptr));
    int random1 = std::rand();
    int random2 = std::rand();

    cout << random1 << '\n' << random2 << '\n';

    return 0;
}