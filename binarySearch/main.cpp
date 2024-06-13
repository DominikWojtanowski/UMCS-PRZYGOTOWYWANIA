#include <iostream>

int main()
{
    int tab[]{10, 15, 22, 35, 65, 77, 91, 101, 102};

    int arrSize = sizeof(tab) / sizeof(tab[0]);

    int expectedNum = 101;
    int low{};
    int high{arrSize - 1};
    int n = low + (high - low) / 2;

    while (tab[n] != expectedNum && high > low)
    {
        if (tab[n] < expectedNum)
            low = n + 1;
        else
            high = n - 1;
        n = low + (high - low) / 2;
    }

    std::cout << n;

    return 0;
};