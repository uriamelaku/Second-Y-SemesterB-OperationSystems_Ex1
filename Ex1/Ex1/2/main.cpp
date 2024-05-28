#include <iostream>
#include "poisson.cpp"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Error: must provide exactly two numbers (lambda, k)\n";
        return 1;
    }

    long double lambda = std::stold(argv[1]);
    int k = std::stoi(argv[2]);

    long double ans = px(lambda, k);

    std::cout << ans << std::endl;

    return 0;
}