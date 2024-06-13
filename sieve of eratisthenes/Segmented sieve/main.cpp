#include <iostream>
#include <cstring>
#include <cmath>

#define ULL unsigned long long
#define LL long long
#define LD long double

ULL *Sieve(ULL);
void SegmentedSieve(ULL n);

int main()
{
    ULL n = 20;
    SegmentedSieve(20);
}

ULL *Sieve(ULL arr_size)
{
    ULL primes_size{arr_size}, prime_index{};
    bool *prime = new bool[arr_size + 1];
    ULL *primes_arr;

    for (size_t i = 0; i < arr_size; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p * p <= arr_size; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= arr_size; i += p)
            {
                prime[i] = false;
                primes_size--;
            }
        }
    }

    primes_arr = new ULL[primes_size];

    for (size_t i = 2; i < arr_size; i++)
        if (prime[i] == true)
        {
            std::cout << i << ", ";
            primes_arr[prime_index++] = i;
        }

    delete[] prime;

    return primes_arr;
};

void SegmentedSieve(ULL n)
{
    ULL limit = std::floor(std::sqrt(n)) + 1;

    ULL *primes = Sieve(limit);
    ULL primes_size = sizeof(primes) / sizeof(primes[0]);
    ULL low{limit}, high{limit * 2};

    while (low < n)
    {
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));

        for (size_t i = 0; i < primes_size; i++)
        {
            if (high >= n)
                high = n;

            int loLim = std::floor(low / primes[i]) * primes[i];
            if (loLim < n)
                loLim += primes[i];

            for (size_t j = loLim; j < high; j += primes[i])
                mark[j - low] = false;
        }

        for (size_t j = low; j < high; j++)
        {
            if (mark[j - low] == true)
                std::cout << j << ", ";
        }

        low += limit;
        high += limit;
    }

    delete[] primes;
}