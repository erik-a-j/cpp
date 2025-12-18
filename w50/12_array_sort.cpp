/**
 * @file 12_array_sort.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-16
 * 
 * @copyright Copyright (c) 2025
 * 
 * 1) Make a function to fill an array of type int with random numbers 
 *    with the range 0 and 99.
 * 2) Make a function to print an array of type int to the output.
 * 3) Make a function to swap values of two int variables.
 * 4) Make a function to sort an array of type int. The function 
 *    shall accept a function pointer of type compare_t to compare two values
 *      using compare_t = bool (*)(int, int);
 *      void sort_array(size_t length, int *arr, compare_t compare);
 * 
 *    a) When you sort the array, 
 *       the compare function shall be used to compare the elements
 * 
 *    b) To swap the elements, the swap function of step 3 shall be used.
 * 
 *    c) Implement two functions, compare_asc and compare_desc, 
 *       to sort the array ascending and descending
 *      bool compare_asc(int a, int b);
 *      bool compare_desc(int a, int b);
 * 
 *    d) You shall be able to sort the array 
 *       ascending and descending by calling sort_array 
 *       with different compare functions
 * 
 * !! To handle the arrays use only pointers !!
 */

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>

template <size_t N>
static void fill_random(int32_t (&arr)[N], int32_t min, int32_t max)
{
    std::ifstream urand("/dev/urandom", std::ios::binary);
    if (urand.is_open())
    {
        uint32_t range = static_cast<uint32_t>(max) - static_cast<uint32_t>(min) + 1u;
        for (int32_t *p = arr; p < (arr + N); ++p)
        {
            uint32_t raw;
            urand.read(reinterpret_cast<char *>(&raw), sizeof(raw));

            uint32_t normalized = raw % range;
            *p = min + static_cast<int32_t>(normalized);
        }
        urand.close();
    }
}

template <size_t N>
static void print_array(const int32_t (&arr)[N])
{
    std::cout << "[" << N << "] = { ";
    for (const int32_t *p = arr; p < (arr + N); ++p)
    {
        std::cout << *p << ((p < (arr + N - 1)) ? ", " : " }\n");
    }
}

static void swap(int32_t *a, int32_t *b)
{
    int32_t tmp = *a;
    *a = *b;
    *b = tmp;
}

using compare_t = bool (*)(int, int);

template <size_t N>
static void sort_array(int32_t (&arr)[N], compare_t compare)
{
    for (int32_t *ip = arr; ip < (arr + N); ++ip)
    {
        for (int32_t *jp = ip + 1; jp < (arr + N); ++jp)
        {
            if (compare(*ip, *jp))
            {
                swap(ip, jp);
            }
        }
    }
}

bool compare_asc(int32_t a, int32_t b)
{
    return a > b;
}
bool compare_desc(int32_t a, int32_t b)
{
    return a < b;
}

int main(void)
{
    int32_t arr[5];
    fill_random(arr, 0, 99);
    print_array(arr);

    sort_array(arr, compare_asc);
    print_array(arr);

    sort_array(arr, compare_desc);
    print_array(arr);
    return 0;
}