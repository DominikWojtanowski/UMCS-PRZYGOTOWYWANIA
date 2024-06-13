#include <iostream>
#include <algorithm>

void merge(int *arr, int left, int mid, int right)
{
    // mam osiem elementow 0,4,9
    //  0 + 4 = 4
    //  mid - left + 1
    // 4 - 0 + 1 = 5
    // 9 - 4 = 5
    int subArrayOneSize{mid - left + 1}, subArrayTwoSize{right - mid};
    int subArrayOneIndex{0}, subArrayTwoIndex{0}, mainArrayIndex{left};

    int *leftArr{new int[subArrayOneSize]}, *rightArr{new int[subArrayTwoSize]};

    for (size_t i = 0; i < subArrayOneSize; i++) // 0 1 2 3 4
        leftArr[i] = arr[left + i];

    for (size_t j = 0; j < subArrayTwoSize; j++) // 5 6 7 8 9
        rightArr[j] = arr[mid + 1 + j];

    while (subArrayOneIndex < subArrayOneSize && subArrayTwoIndex < subArrayTwoSize)
    {
        if (leftArr[subArrayOneIndex] <= rightArr[subArrayTwoIndex])
        {
            arr[mainArrayIndex] = leftArr[subArrayOneIndex];
            subArrayOneIndex++;
        }
        else
        {
            arr[mainArrayIndex] = rightArr[subArrayTwoIndex];
            subArrayTwoIndex++;
        }
        mainArrayIndex++;
    }

    while (subArrayTwoIndex < subArrayTwoSize)
    {
        arr[mainArrayIndex] = rightArr[subArrayTwoIndex];
        mainArrayIndex++;
        subArrayTwoIndex++;
    }

    while (subArrayOneIndex < subArrayOneSize)
    {
        arr[mainArrayIndex] = leftArr[subArrayOneIndex];
        mainArrayIndex++;
        subArrayOneIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}
void mergeSort(int *arr, int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int tab[]{12, 1, 100, 98, 7, 65, 3, 33, 41, 23};
    int arrSize = sizeof(tab) / sizeof(tab[0]);

    mergeSort(tab, 0, arrSize - 1);
    printArray(tab, arrSize);

    return 0;
}