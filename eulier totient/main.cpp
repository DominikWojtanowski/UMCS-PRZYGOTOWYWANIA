#include <iostream>
#include <algorithm>
#include <numeric>

#define ULL unsigned long long
#define LL long long
#define LD long double

constexpr ULL EuilerTotient(ULL);

int main()
{
    std::cout << EuilerTotient(10000) << std::endl;
}

constexpr ULL EuilerTotient(ULL num)
{
    ULL res{num};
    if (num % 2 == 0)
    {
        while (num % 2 == 0)
            num /= 2;

        res -= res / 2;
    }
    if (num % 3 == 0)
    {
        while (num % 3 == 0)
            num /= 3;

        res -= res / 3;
    }

    for (size_t i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0)
        {
            while (num % i == 0)
                num /= i;

            res -= res / i;
        }
        if (num % (i + 2) == 0)
        {
            while (num % (i + 2) == 0)
                num /= (i + 2);

            res -= res / (i + 2);
        }
    }

    if (num > 1)
        res -= res / num;

    return res;
}