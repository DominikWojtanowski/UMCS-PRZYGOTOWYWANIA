#include <iostream>

size_t CiagFibonacciego(size_t n)
{
    size_t tmp[n+1];
    tmp[0] = 0;
    tmp[1] = 1;
    for (size_t i = 2; i <= n; i++)
        tmp[i] = tmp[i-1] + tmp[i-2];

    return tmp[n];
}

int main()
{
    size_t wartosc;
    std::cin >> wartosc;
    std::cout << "Ciag fibanacciego to: " << CiagFibonacciego(wartosc) << std::endl;
}