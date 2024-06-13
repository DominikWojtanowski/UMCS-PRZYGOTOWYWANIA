#include <iostream>
#include <algorithm>

struct Package
{
    int priority;
    int size;
};

void insertionSort(int *arr, int arrSize)
{
    int j{}, key{};
    for (size_t i = 1; i < arrSize; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    Package tab[]{{1, 0}, {4, 2}, {-4, 2}, {4, 1}};
    Package **packageArr{nullptr};

    int *indexesArr{nullptr};

    long long max, min, which;
    max = 4;
    min = -4;

    long long bucketSize{}, lenght{};
    long long n{4}, k{2}, singlePrzedzial{};

    bucketSize = n / k;
    bucketSize = bucketSize == 0 ? 1 : bucketSize;

    singlePrzedzial = (max - min) / bucketSize;
    singlePrzedzial = singlePrzedzial == 0 ? max - min + 1 : singlePrzedzial;

    packageArr = new Package *[bucketSize];
    indexesArr = new int[bucketSize]{};
    for (size_t j = 0; j < bucketSize; j++)
    {
        packageArr[j] = new Package[singlePrzedzial * 2];
    }

    std::cout << "bucketSize: " << bucketSize << "\n";
    std::cout << "singleRange: " << singlePrzedzial << "\n";
    std::cout << "First Bucket Size: " << singlePrzedzial * 2 << "\n";

    for (size_t j = 0; j < 4; j++)
    {
        std::cout << tab[j].priority << "\n";
    }

    return 0;
}