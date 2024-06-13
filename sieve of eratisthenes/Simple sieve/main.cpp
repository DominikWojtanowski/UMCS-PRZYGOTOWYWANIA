#include <iostream>
#include <cstring>

#define ULL unsigned long long
#define LL long long
#define LD long double

bool *Sieve(ULL);

int main()
{
    ULL arr_size{};
    std::cin >> arr_size;

    bool *all_primes = Sieve(arr_size);

    for (size_t i = 0; i < arr_size; i++)
        if (all_primes[i] == true)
            std::cout << std::boolalpha << "all_primes[" << i << "]: " << all_primes[i] << std::endl;

    delete[] all_primes;
}

bool *Sieve(ULL arr_size)
{
    bool *prime = new bool[arr_size + 1];

    for (size_t i = 0; i < arr_size; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p * p <= arr_size; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= arr_size; i += p)
                prime[i] = false;
        }
    }

    return prime;
};