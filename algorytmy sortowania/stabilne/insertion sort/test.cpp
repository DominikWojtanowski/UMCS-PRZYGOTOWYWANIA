#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <cstdlib>

// Twoja implementacja
void insertionSortYourVersion(int *arr, int sizeArr)
{
    int whichElement = 0, tmp = 0, key;

    for (size_t i = 0; i < sizeArr; i++)
    {
        key = arr[i];
        whichElement = i;

        for (long long j = 0; j < i; j++)
        {
            if (key < arr[j])
            {
                whichElement = j;
                break;
            }
        }

        tmp = arr[whichElement];
        arr[whichElement] = key;

        for (long long j = whichElement + 1; j <= i; j++)
        {
            std::swap(arr[j], tmp);
        }
    }
}

// Poprawiona implementacja
void insertionSort(int *arr, int sizeArr)
{
    for (int i = 1; i < sizeArr; i++)
    {
        int key = arr[i];
        int j = i - 1;

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
    const int size = 1000;
    int tab1[size], tab2[size];

    // Inicjalizacja tablicy losowymi wartościami
    for (int i = 0; i < size; i++)
    {
        int value = rand() % 10000;
        tab1[i] = value;
        tab2[i] = value;
    }

    // Pomiar czasu dla Twojej wersji
    auto start = std::chrono::high_resolution_clock::now();
    insertionSortYourVersion(tab1, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Czas wykonania Twojej wersji: " << duration.count() << " sekund\n";

    // Pomiar czasu dla poprawionej wersji
    start = std::chrono::high_resolution_clock::now();
    insertionSort(tab2, size);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Czas wykonania poprawionej wersji: " << duration.count() << " sekund\n";

    return 0;
}
