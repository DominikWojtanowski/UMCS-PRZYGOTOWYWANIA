#include <iostream>
#include <algorithm>

#define ULL unsigned long long
#define LL long long
#define LD long double

int main()
{
    ULL arr_size{};
    LL *arr;

    std::cin >> arr_size;
    arr = new LL[arr_size];

    for (size_t i = 0; i < arr_size; i++)
        std::cin >> arr[i];

    std::sort(arr, arr + arr_size);

    for (size_t i = 0; i < arr_size; i++)
        std::cout << arr[i] << ", ";

    if (arr_size & 1)
        std::cout << std::endl
                  << arr[arr_size / 2];
    else
        std::cout << std::endl
                  << arr[arr_size / 2 - 1];

    delete[] arr;
    return 0;
}