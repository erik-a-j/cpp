#include <iostream>

static bool is_prime(int num) {
    bool status = true;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            status = false;
            break;
        }
    }
    return status;
}

int main(void) {
    int num{};
    std::cout << "Enter number: ";
    std::cin >> num;
    if (std::cin.good()) {
        std::cout << std::boolalpha << is_prime(num) << std::noboolalpha << '\n';
    }
    return 0;
}