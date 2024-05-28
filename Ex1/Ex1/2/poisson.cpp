#include <cmath>
#include <iostream>
#include "poisson.hpp"

long double px(long double lambda, int k)
{
    long double px = expf(-lambda) * std::pow(lambda, k) / std::tgamma(k + 1);
    return px;
}