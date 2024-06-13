#include <iostream>
#include <algorithm>

#define ULL unsigned long long
#define LL long long
#define LD long double

constexpr ULL sumAllFactorsOfANumber(ULL);

int main()
{
    std::cout << sumAllFactorsOfANumber(1800) << std::endl;
    return 0;
}

constexpr ULL sumAllFactorsOfANumber(ULL num)
{
    ULL sum{};
    for (size_t i = 1; i * i < num; i++)
    {
        if (num % i == 0)
        {
            if ((num / i) != (i))
                sum += (num / i) + i;
            else
                sum += i;
        }
    }

    return sum;
}