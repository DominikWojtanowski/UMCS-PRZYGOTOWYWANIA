#include <iostream>

#define ULL unsigned long long
#define LL long long
#define LD long double

bool isPrime(ULL num)
{
    if (num == 0 || num == 1)
        return false;
    if (num <= 3)
        return true;
    if (~num & 1 || num % 3 == 0)
        return 0;

    for (size_t i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0) // sprawdzamy zarowno czy jest podzielne przez  6k - 1 oraz 6k + 1
            return false;
    }
    return true;
}

int main()
{
    ULL sprawdz_liczbe;
    std::cin >> sprawdz_liczbe;

    std::cout << std::boolalpha << isPrime(sprawdz_liczbe) << std::endl;
    return 0;
}