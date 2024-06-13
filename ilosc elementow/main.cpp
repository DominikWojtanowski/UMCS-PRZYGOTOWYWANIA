#include <iostream>
#include <algorithm>

int main()
{
    int tab[]{5, 2, 8, 9, 4}, tab2[]{3, 2, 9, 5, 4};
    int sizeOne{sizeof(tab) / sizeof(tab[0])}, sizeTwo{sizeof(tab2) / sizeof(tab2[0])};

    std::sort(tab, tab + sizeOne);
    std::sort(tab2, tab2 + sizeTwo);

    int i{}, j{}, count{};

    while (i < sizeOne && j < sizeTwo)
    {
        if (tab[i] > tab2[j])
            j++;
        else if (tab[i] < tab2[j])
            i++;
        else
        {
            j++;
            i++;
            count++;
        }
    }
    std::cout << count << std::endl;

    return 0;
}