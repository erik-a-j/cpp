/**
 * @file 8_rand_arr_ptr.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-11
 * 
 * @copyright Copyright (c) 2025
 * 
 * Make a program to fill a 10-element int array with random numbers 
 * in the range of 0 and 99, then print the array to the output.
 * sort the array ascending(from the smallest to the largest) and then
 * Print the sorted array to the output.
 * 
 * !!! To fill, print and sort the array use only pointers. !!!
 */

#include <cstdint>
#include <fstream>
#include <iostream>

#define ARRSIZE(a) sizeof(a) / sizeof(a[0])
#define RANDOM_MIN 0
#define RANDOM_MAX 99

static int get_random(int min, int max)
{
    int rv = 0;
    uint32_t raw = 0;

    std::ifstream urand("/dev/urandom", std::ios::binary);
    if (urand.is_open())
    {
        urand.read(reinterpret_cast<char *>(&raw), sizeof(raw));
        urand.close();

        uint32_t range = static_cast<uint32_t>(max) - static_cast<uint32_t>(min) + 1u;
        uint32_t normalized = raw % range;
        rv = min + static_cast<int>(normalized);
    }
    return rv;
}

template <size_t N>
static void print_array(const int (&arr)[N])
{
    std::cout << "array[" << N << "] = { ";
    for (const int *p = arr; p < (arr + N); ++p)
    {
        std::cout << *p;
        if (p < (arr + N - 1))
        {
            std::cout << ", ";
        } else
        {
            std::cout << " }\n";
        }
    }
}

using compare = bool (*)(int a, int b);

template <size_t N>
static void sort_array(int (&arr)[N], compare cmp)
{
    for (int *pi = arr; pi < (arr + N); ++pi)
    {
        for (int *pj = pi + 1; pj < (arr + N); ++pj)
        {
            if (cmp(*pi, *pj))
            {
                int tmp = *pi;
                *pi = *pj;
                *pj = tmp;
            }
        }
    }
}

bool cmp_asc(int a, int b)
{
    return a > b;
}
bool cmp_dsc(int a, int b)
{
    return a < b;
}

int main(void)
{
    int arr[10];
    for (int *p = arr; p < (arr + ARRSIZE(arr)); ++p)
    {
        *p = get_random(RANDOM_MIN, RANDOM_MAX);
    }

    print_array(arr);

    sort_array(arr, cmp_asc);
    print_array(arr);
    sort_array(arr, cmp_dsc);
    print_array(arr);

    return 0;
}