#include <iostream>
#include <cmath>

#define ULL unsigned long long
#define LL long long
#define LD long double

ULL AllPrimeFactors(ULL);

int main()
{
    ULL num;
    std::cin >> num;
    std::cout << "Count of all prime factors: " << AllPrimeFactors(num) << std::endl;
    return 0;
}

ULL AllPrimeFactors(ULL num)
{
    ULL count{};
    ULL tmp_num{num};

    while (num % 2 == 0)
    {
        count++;
        std::cout << 2 << " ";
        num /= 2;
    }

    while (num % 3 == 0)
    {
        count++;
        num /= 3;
        std::cout << 3 << " ";
    }

    for (int i = 5; i * i <= num; i += 6)
    {
        // While i divides n, print i and divide n
        while (num % i == 0)
        {
            count++;
            num = num / i;
        }

        while (num % (i + 2) == 0)
        {
            count++;
            num = num / (i + 2);
        }
    }

    if (num > 2)
    {
        std::cout << num << std::endl;
        count++;
    }

    if (num == tmp_num)
        return 1;
    std::cout << std::endl;

    return count;
}