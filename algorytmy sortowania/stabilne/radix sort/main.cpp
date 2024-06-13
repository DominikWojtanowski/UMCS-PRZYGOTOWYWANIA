#include <iostream>
#include <algorithm>

void countingSort(int *arr, int arrSize, int przezIle)
{
    int countArr[10]{};
    int outputArr[arrSize]{};

    for (size_t i = 0; i < arrSize; i++)
        countArr[(arr[i] / przezIle) % 10]++;

    for (size_t i = 1; i < 10; i++)
        countArr[i] += countArr[i - 1];

    for (long long i = arrSize - 1; i >= 0; i--)
        outputArr[--countArr[(arr[i] / przezIle) % 10]] = arr[i];

    for (int i = 0; i < arrSize; i++)
        arr[i] = outputArr[i];
}

void radixSort(int *arr, int arrSize, int maxElement)
{
    for (long long i = 1; (maxElement / i) > 0; i *= 10)
        countingSort(arr, arrSize, i);
}

int main()
{
    int arr[]{170, 45, 75, 90, 802, 24, 2, 66};
    int maxEle = *std::max_element(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    radixSort(arr, sizeof(arr) / sizeof(arr[0]), maxEle);
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[i]); i++)
        std::cout << arr[i] << ", ";

    return 0;
}