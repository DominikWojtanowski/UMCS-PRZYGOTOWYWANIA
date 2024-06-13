#include <iostream>
#include <algorithm>

#define ULL unsigned long long
#define LL long long
#define LD long double

constexpr ULL printAllFactorsOfANumber(ULL);

int main()
{
    std::cout << printAllFactorsOfANumber(1800) << std::endl;
    return 0;
}

constexpr ULL printAllFactorsOfANumber(ULL num)
{
    ULL sum{};
    for (size_t i = 1; i * i < num; i++)
    {
        if (num % i == 0)
        {
            if ((num / i) != (i))
                std::cout << num / i << ", " << i << ", ";
            else
                std::cout << i << ", ";
        }
    }

    return sum;
}