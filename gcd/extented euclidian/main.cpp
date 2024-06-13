#include <iostream>
#include <algorithm>
#include <numeric>

#define ULL unsigned long long
#define LL long long
#define LD long double

constexpr ULL ExtendedEuclidianGCD(ULL, ULL, ULL *, ULL *);

int main()
{
    ULL x, y;
    ULL gcd = ExtendedEuclidianGCD(10, 24, &x, &y);
    std::cout << gcd << std::endl;
    return 0;
}

constexpr ULL ExtendedEuclidianGCD(ULL a, ULL b, ULL *x, ULL *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    ULL x1{}, y1{};
    ULL d = ExtendedEuclidianGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - y1 * (a / b);

    return d;
}
