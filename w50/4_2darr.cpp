#include <iostream>

void print3x3(const int (&arr)[3][3]) {
    std::cout << "array = {\n";
    for (auto const &arri : arr) {
        std::cout << "  { ";
        for (auto const &arrj : arri) {
            std::cout << arrj << ", ";
        }
        std::cout << "},\n";
    }
    std::cout << "}\n";
}

int main(void) {
    int array[3][3]{};

    std::cout << "Enter the 3 first numbers: ";
    std::cin >> array[0][0] >> array[0][1] >> array[0][2];
    std::cout << "Enter the 3 second numbers: ";
    std::cin >> array[1][0] >> array[1][1] >> array[1][2];
    std::cout << "Enter the 3 last numbers: ";
    std::cin >> array[2][0] >> array[2][1] >> array[2][2];

    print3x3(array);
    return 0;
}