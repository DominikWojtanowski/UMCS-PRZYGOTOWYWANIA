// C++ implementation of Shell Sort
#include <iostream>
using namespace std;

/* function to sort arr using shellSort */
void shellSort(int arr[], int n)
{
    for (long long gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            std::cout << i << std::endl;
            long long tmp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = tmp;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {10, 1, 15, 7, 22}, i;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: \n";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "\nArray after sorting: \n";
    printArray(arr, n);

    return 0;
}