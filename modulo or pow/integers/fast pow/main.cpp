#include <iostream>
#include <algorithm>
#include <numeric>

#define ULL unsigned long long
#define LL long long
#define LD long double

constexpr ULL FastPow(ULL, ULL);

int main()
{
    std::cout << FastPow(2, 16) << std::endl;
    return 0;
}

constexpr ULL FastPow(ULL num, ULL pow)
{
    ULL res{1};
    while (pow > 0)
    {
        if (pow & 1)
            res *= num;

        pow >>= 1;
        num *= num;
    }

    return res;
}