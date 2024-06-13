#include <iostream>
#include <algorithm>

void insertionSort(int *arr, int sizeArr)
{
    int key{}, j{};
    for (size_t i = 1; i < sizeArr; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int tab[]{23, 111, 10, 5, 2};

    insertionSort(tab, sizeof(tab) / sizeof(int));

    std::for_each(tab, tab + 5, [](int element)
                  { std::cout << element << ", "; });
    return 0;
}