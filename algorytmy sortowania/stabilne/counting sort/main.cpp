#include <iostream>
#include <algorithm>

int *countingSort(int *arr, int arrSize, int max)
{
    int *tabOutput = new int[arrSize]{};
    int countArr[max + 1]{};

    for (size_t i = 0; i < arrSize; i++)
        countArr[arr[i]]++;

    for (size_t i = 1; i < arrSize; i++)
        countArr[i] += countArr[i - 1];

    for (long long i = arrSize - 1; i >= 0; i--)
    {
        tabOutput[--countArr[arr[i]]] = arr[i];
    }

    return tabOutput;
}

int main()
{

    int tab[]{2, 5, 3, 0, 2, 3, 0, 3};

    int max = *std::max_element(tab, tab + 5, [](int element, int element2)
                                { return element < element2; });

    int *tab2 = countingSort(tab, sizeof(tab) / sizeof(tab[0]), max);
    std::for_each(tab2, tab2 + sizeof(tab) / sizeof(tab[0]), [&](int element)
                  { std::cout << element << "\n"; });

    delete[] tab2;
    return 0;
}