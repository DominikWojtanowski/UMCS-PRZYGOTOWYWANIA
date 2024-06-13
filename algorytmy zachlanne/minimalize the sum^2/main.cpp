#include <iostream>
#include <algorithm>

#define ULL unsigned long long
#define LL long long
#define LD long double

int main()
{
    ULL arr_size{}, sum{}, tmp{};

    std::cin >> arr_size;

    for (size_t i = 0; i < arr_size; i++)
    {
        std::cin >> tmp;
        sum += tmp;
    }

    std::cout << sum / arr_size;

    return 0;
}