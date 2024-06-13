#include <iostream>
#include <algorithm>

using namespace std;
int partition(int *arr, int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (size_t j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int *arr, int low, int high)
{
    if (low >= high)
        return;

    int pivotPos = partition(arr, low, high);

    quickSort(arr, low, pivotPos - 1);
    quickSort(arr, pivotPos + 1, high);
}


int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Function call
    quickSort(arr, 0, n - 1);
    // Print the sorted array
    cout << "Sorted Array\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
// This Code is Contributed By Diwakar Jha