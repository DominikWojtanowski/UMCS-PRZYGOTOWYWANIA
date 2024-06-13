#include <iostream>
#include <algorithm>

int main()
{
    int tab[]{3, 2, -5, 10, -5};

    int sum{}, best{};
    for (size_t i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
    {
        sum = std::max(tab[i], sum + tab[i]); // albo trzymamy sie obecnego ciagu, albo zaczynamy nowy od  poczatku
        best = std::max(best, sum);           // abo suma z poprzedniego ciagu jest lepsza, albo suma z nowego ciagu jest lepsza
    }
    std::cout << best << std::endl;

    return 0;
}