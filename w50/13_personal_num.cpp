/**
 * @file 13_personal_num.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-16
 * 
 * @copyright Copyright (c) 2025
 * 
 * The Luhn algorithm, also known as modulus 10 algorithm, 
 * is a simple checksum method used to detect errors in a variety of identification numbers, 
 * such as credit card numbers and Swedish personal identity numbers (personnummer).
 * 
 *  In a 10-digit personnummer (YYMMDD-nnnC), YYMMDD is the birth date, 
 *  nnn is a serial number which is called birth number and the last digit (C) is a control digit. 
 *  The control digit is calculated:
 * 
 *   The numbers in the birth date and the birth number are alternately multiplied by 2 and 1.
 *   Sum all the digits in each product.
 *   If a product is larger than 9, each digit in the number is used. 
 *   For example, 13 will be 1 + 3
 *   The first digit of the sum is subtracted from 10
 *   The remainder of the division of the result of the previous step by 10 is the control bit.
 *   For example: 811218-987
 *    8 × 2  +  1 × 1  +  1 × 2  +  2 × 1  +  1 × 2  +  8 × 1  +  9 × 2  +  8 × 1  +  7 × 2 
 *    16        1         2         2         2         8         18        8         14
 *    (1+6)  +  1      +  2      +  2      +  2      +  8      +  (1+8)  +  8      +  (1+4) = 44
 *   
 *   The control digit (C) is (10 - (44 % 10)) % 10 = 6
 *   So the personnummer is  811218-9876
 * 
 * Make a program to read personal identity numbers (personnummer) 
 * in the format of YYMMDD-nnnC from the terminal and 
 * check if the personnummer is correct or not. 
 * You need to calculate the control digit of the personnummer 
 * and compare it with the last digit of what the user has entered. 
 * If the calculated one and the one entered by the user are the same, 
 * it means that the personnummer is correct. Otherwise, 
 * the entered personnummer is not a valid personnummer. 
 * Please note that the format of the personnummer shall also be checked.
 * 
 * No magic numbers!
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

#define BIRTHDATENUM_LEN 9

static int calculate_C_digit(const char *s)
{
    int c{};
    int sum{};
    for (int i = 0; i < BIRTHDATENUM_LEN; ++i)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return -1;
        }
        int d = s[i] - '0';
        int tmp = d * (((i + 1) % 2) + 1);
        if (tmp > 9)
        {
            tmp = 1 + (tmp % 10);
        }
        sum += tmp;
    }
    c = (10 - (sum % 10)) % 10;
    return c;
}

int main(int argc, char *argv[])
{
    std::string input;
    if (argc == 2)
    {
        input.assign(argv[1]);
    }
    else
    {
        std::cout << "Enter personnummer \x1b[1m[YYMMDD-XXXX]\x1b[m: ";
        std::getline(std::cin, input);
    }
    auto birth_date_begin = std::find_if(input.begin(), input.end(), [](char c) {
        return !std::isspace(c);
    });
    auto birth_date_end = std::find_if(birth_date_begin, input.end(), [](char c) {
        return c == '-';
    });
    auto last4_begin = std::find_if(birth_date_end, input.end(), [](char c) {
        return std::isdigit(c);
    });
    auto last4_end = std::find_if(last4_begin, input.end(), [](char c) {
        return !std::isalnum(c);
    });

    std::string birth_date(birth_date_begin, birth_date_end);
    std::string last4(last4_begin, last4_end);
    if (birth_date.size() == 8)
    {
        birth_date = birth_date.substr(2);
    }
    if (last4.size() == 3)
    {
        last4.append(1, 'X');
    }
    else if (birth_date.size() != 6 || last4.size() != 4)
    {
        std::cerr << "\x1b[38;5;196mERROR:\x1b[m Invalid personnummer format\n";
        return 1;
    }

    std::string serial(birth_date + last4);
    int c_digit = calculate_C_digit(serial.data());
    if (c_digit == -1)
    {
        std::cerr << "\x1b[38;5;196mERROR:\x1b[m Failed to calculate check digit\n";
        return 1;
    }
    if (last4[3] < '0' || last4[3] > '9')
    {
        std::cout << "check digit for '" << birth_date << '-' << last4.substr(0, 3) << "' is '" << c_digit << "'\n";
    }
    else if (c_digit == last4[3] - '0')
    {
        std::cout << "'" << birth_date << '-' << last4 << "' is \x1b[38;5;46ma valid\x1b[m personnummer\n";
    }
    else
    {
        std::cout << "'" << birth_date << '-' << last4 << "' is \x1b[38;5;196mnot a valid\x1b[m personnummer\n";
    }

    return 0;
}