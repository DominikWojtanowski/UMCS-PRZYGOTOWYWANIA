#include <iostream>
#include <string>

int main()
{
    long long liczba, podstawa, iloraz;
    size_t reszta;
    std::cin >> liczba >> podstawa;

    if (liczba == 0)
        std::cout << "0";
    while (liczba > 0)
    {
        iloraz = liczba / podstawa;
        reszta = liczba % podstawa;

        if (podstawa == 16)
        {
            if (reszta >= 10)
                std::cout << static_cast<char>(reszta + 55);
            else
                std::cout << reszta;
        }
        else
            std::cout << reszta;
        liczba = iloraz;
    }

    return 0;
}