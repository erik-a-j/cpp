/**
 * @file 3_rand_arr.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief g++ 3_rand_arr.cpp
 * @version 0.1
 * @date 2025-12-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <algorithm>
#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>

template <typename T, size_t n>
static void print_array(const std::array<T, n> &arr)
{
    std::cout << "array = { ";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        if (i != arr.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << " }\n";
}

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

int main(void)
{
    std::array<int, 10> arr;

    for (int &arr_i : arr)
    {
        arr_i = get_random(0, 99);
    }
    print_array(arr);

    std::sort(arr.begin(), arr.end(), [](int a, int b) { return a < b; });
    print_array(arr);

    return 0;
}