#include <iostream>
#include "poisson.cpp"

int main() {

    long double lambda[] = {2, 2, 2, 3, 100};
    int k[] = {1, 10, 2, 3, 3};

    for(int i=0; i<5; i++){
        long double ans = px(lambda[i], k[i]);
        std::cout << "k: " << k[i] << "\tlambda: " << lambda[i] << "\t >> poison: " << ans << std::endl;
    }

    return 0;
}