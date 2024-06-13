#include <iostream>
#include <algorithm>
#include <numeric>

#define ULL unsigned long long
#define LL long long
#define LD long double

constexpr ULL FastModPow(ULL, ULL, ULL);

int main()
{
    std::cout << FastModPow(2, 5, 13);
    return 0;
}

constexpr ULL FastModPow(ULL num, ULL pow, ULL mod)
{
    ULL res{1};

    num = num % mod;

    if (num == 0)
        return 0;

    while (pow > 0)
    {
        if (pow & 1)
            res = (res * num) % mod;

        pow >>= 1;
        num = (num * num) % mod;
    }

    return res;
}