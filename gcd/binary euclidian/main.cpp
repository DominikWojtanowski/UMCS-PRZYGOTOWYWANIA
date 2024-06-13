#include <iostream>
#include <algorithm>
#include <numeric>

#define ULL unsigned long long
#define LL long long
#define LD long double

constexpr ULL binaryEuclidian(ULL, ULL);

int main()
{
    ULL wynik = binaryEuclidian(10, 24);
    std::cout << wynik << std::endl;
}

constexpr ULL binaryEuclidian(ULL a, ULL b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    ULL k{};

    while ((~a & 1) && (~b & 1))
    {
        a >>= 1;
        b >>= 1;

        k++;
    }

    while (~a & 1)
        a >>= 1;

    do
    {
        while (~b & 1)
            b >>= 1;

        if (b < a)
            std::swap(a, b);

        b = (b - a);

    } while (b != 0);

    return a <<= k;
}