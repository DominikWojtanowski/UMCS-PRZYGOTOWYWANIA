#include <iostream>
#include <algorithm>

int main()
{
    int tab[]{1, 2, 2, 3, 4, 2, 1, 2}; // tablica musi byc posortowana
    int tabSize = sizeof(tab) / sizeof(tab[0]);

    std::sort(tab, tab + tabSize);

    auto a = std::lower_bound(tab, tab + tabSize, 2);
    auto b = std::upper_bound(tab, tab + tabSize, 2);
    std::cout << b - a << "\n";

    return 0;
}