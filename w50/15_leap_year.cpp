/**
 * @file 15_leap_year.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 * Make a program to read date time in the format of YYYY-MM-DD HH:mm:ss from the input and validate it.
 * A leap year is exactly divisible by 4 except for century years (years ending with 00).
 * The century year is a leap year only if it is perfectly divisible by 400. 
 * If the year is a leap year, then February 29, is the leap day.
 */

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#define DATEFORMAT     "YYYY-MM-DD HH:mm:ss"
#define DATEFORMAT_FMT "%Y-%m-%d %T"

static std::string get_date_input()
{
    std::string input;
    std::cout << "Enter date (" DATEFORMAT "): ";
    std::getline(std::cin, input);
    return input;
}
enum {
    JAN,
    FEB,
    MAR,
    APR,
    MAJ,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC,
};
static std::unordered_map<int, int> month_days = {
    {JAN, 31}, {FEB, 28}, {MAR, 31}, {APR, 30}, {MAJ, 31}, {JUN, 30},
    {JUL, 31}, {AUG, 31}, {SEP, 30}, {OCT, 31}, {NOV, 30}, {DEC, 31},
};
static bool is_leap_year(const std::tm& tm)
{
    int year = tm.tm_year + 1900;
    bool is_leap;
    if (year % 100 == 0)
    {
        is_leap = (year % 400 == 0);
    }
    else
    {
        is_leap = (year % 4 == 0);
    }
    return is_leap;
}
static bool date_valid(const std::tm& tm)
{
    int days_in_month = month_days[tm.tm_mon];

    if (tm.tm_mon == FEB && is_leap_year(tm))
    {
        days_in_month += 1;
    }
    bool valid = (tm.tm_mday <= days_in_month);
    return valid;
}

int main(int argc, char *argv[])
{
    std::string input;
    if (argc >= 2)
    {
        input.assign(argv[1]);
        if (argc == 3)
        {
            input += ' ';
            input += argv[2];
        }
    }
    else
    {
        input = get_date_input();
    }

    std::stringstream ss{input};
    std::tm tm{};
    bool valid{false};
    while (!valid)
    {
        ss >> std::get_time(&tm, DATEFORMAT_FMT);
        if (!ss || !date_valid(tm))
        {
            input = get_date_input();
            ss = std::stringstream{input};
            tm = std::tm{};
        }
        else
        {
            valid = true;
        }
    }

    std::cout << std::put_time(&tm, "%c") << '\n';
    std::cout << "is " << (is_leap_year(tm) ? "a " : "not a ") << "leap year\n";

    return 0;
}