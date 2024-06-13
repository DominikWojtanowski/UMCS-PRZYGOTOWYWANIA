#include <iostream>
#include <cmath>
#include <algorithm>

long long lehmerGCD(std::string a, std::string b)
{
    // do zrobienia, kurewsko zaawansowane
}
long long binaryGCDIterative(long long a, long long b)
{
    if (a == b)
        return a;

    if (a == 0)
        return b;

    if (b == 0)
        return a;

    int k;
    for (k = 0; (a | b) & 1 == 0; k++)
    {
        a >>= 1;
        b >>= 1;
    }

    while (a & 1 == 0)
    {
        a >>= 1;
    }

    do
    {
        while (b & 1 == 0)
        {
            b >>= 1;
        }

        if (a >= b)
            std::swap(a, b);

        b = std::abs(a - b);

    } while (b != 0);

    return a << k;
}
long long binaryGCDRecursive(long long a, long long b)
{
    if (a == b)
        return a;

    // GCD(0, b) == b; GCD(a, 0) == a,
    // GCD(0, 0) == 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (~a & 1) // if a % 2 == 0
    {
        if (b & 1) // if b % 2 == 1
            return binaryGCDRecursive(a >> 1, b);
        else
            return binaryGCDRecursive(a >> 1, b >> 1) << 1; // << 1 = * 2
    }

    if (b & 1)
        return binaryGCDRecursive(a, b >> 1);
    else
        return binaryGCDRecursive(std::abs(a - b) >> 1, b);
}
std::string callSuitableAlgorithm(std::string a, std::string b)
{
}
long long callSuitableAlgorithm(long long a, long long b)
{
    return binaryGCDIterative(a, b);
}
long long LCM(long long a, long long b)
{
    return (a * b) / binaryGCDIterative(a, b);
}
int main()
{
    long long p, q;
    std::cin >> p >> q;

    long long n = p * q;
    long long lambda = LCM(p - 1, q - 1);

    long long e;
    for (e = 2; binaryGCDIterative(e, lambda) != 1; e++)
    {
    }

    long long d;

    for (d = 2; (((e * d) % lambda) != 1); ++d)
    {
    }

    std::cout << "d = " << d << " and e = " << e << " and lambda = " << lambda << std::endl;
    // do dokonczenia tego algorytmu jest mi potrzebna implementajca bigint

    return 0;
}