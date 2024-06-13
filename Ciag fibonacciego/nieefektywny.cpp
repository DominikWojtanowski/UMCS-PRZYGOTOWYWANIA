#include <iostream>

size_t CiagFibonacciego(size_t wartosc)
{
    return wartosc < 2 ? wartosc : CiagFibonacciego(wartosc - 1) + CiagFibonacciego(wartosc - 2);
}

int main()
{
    size_t wartosc;
    std::cin >> wartosc;
    std::cout << "Wartosc ciagu fibonacciego to: " << CiagFibonacciego(wartosc) << std::endl;
}