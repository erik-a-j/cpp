/**
 * @file 10_person_t.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025
 * 
 * Make a struct type named person_t which has, name, age and id members.
 * Make a program to create an array of 3 persons. 
 * Then read 3 persons from the standard input and then 
 * sort the persons according thier ids and print the persons to the standard output.
 * 
 * !! To sort and print use only pointers. !!
 */

#include <cctype>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>

struct person_t {
    std::string name;
    int age;
    int id{1};
};

template <size_t N>
static void init_person_array(person_t (&array)[N])
{
    for (person_t *p = array; p < (array + N); ++p)
    {
        p->name.clear();
        p->age = 0;
        p->id += static_cast<int>(p - array);
    }
}

template <size_t N>
static void print_person_array(person_t (&array)[N])
{
    std::cout << "persons:\n";
    for (person_t *p = array; p < (array + N); ++p)
    {
        std::cout << "  name: " << p->name << ", age: " << p->age << ", id: " << p->id << '\n';
    }
}

int main(void)
{
    person_t persons[3];
    init_person_array(persons);

    for (person_t *p = persons; p < (persons + 3);)
    {
        std::string line;
        std::cout << "Enter (\"name\" age) for person[" << p - persons << "]: ";
        std::getline(std::cin >> std::ws, line);

        for (auto i = line.begin(); i != line.end(); ++i)
        {
            if (std::isdigit(*i))
            {
                p->name = std::string(line.begin(), i - 1);
                p->age = 0;
                for (auto j = i; j != line.end(); ++j)
                {
                    p->age *= 10;
                    p->age += *j - '0';
                }
                break;
            }
        }
        if (std::cin.good())
        {
            ++p;
        }
    }

    print_person_array(persons);
    return 0;
}