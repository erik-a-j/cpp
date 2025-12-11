/**
 * @file 9_2darr_ptr.cpp
 * @author Erik Johansson (erik.alexius.johansson@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-11
 * 
 * @copyright Copyright (c) 2025
 * 
 * Make a program to fill a 2D array (2x3) of type int 
 * with random numbers in the range of 0 and 99 
 * and then print the array to the terminal.
 * 
 * !!! To fill and print the array, use only pointers. !!!
 */

#include <cstdint>
#include <fstream>
#include <iostream>

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

template <typename T, size_t N>
using matrix_t = T[2][N];

template <typename T, size_t N>
static void print_matrix(const matrix_t<T, N>& matrix)
{
    std::cout << "[2][" << N << "] = {\n";
    for (const T(*prow)[N] = matrix; prow < (matrix + 2); ++prow)
    {
        std::cout << "  { ";
        for (const T *pcol = *prow; pcol < (*prow + N); ++pcol)
        {
            std::cout << *pcol;
            if (pcol < (*prow + N - 1))
            {
                std::cout << ", ";
            } else
            {
                std::cout << " },\n";
            }
        }
    }
    std::cout << "}\n";
}

int main(void)
{
    matrix_t<int, 3> matrix;

    for (int (*prow)[3] = matrix; prow < (matrix + 2); ++prow)
    {
        for (int *pcol = *prow; pcol < (*prow + 3); ++pcol)
        {
            *pcol = get_random(0, 99);
        }
    }

    print_matrix(matrix);
    return 0;
}