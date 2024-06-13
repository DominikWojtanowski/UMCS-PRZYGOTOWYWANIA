#include <iostream>
#include <algorithm>

int ok(int wartosc)
{
    return wartosc < 133 ? wartosc * 10 : 1;
}
int main()
{
    int k{1}, prevk{1}, mid{};

    if (ok(k) > ok(k + 1))
    {
        std::cout << k << std::endl;
        return 0;
    }

    while (ok(k <<= 1) > ok(prevk))
        prevk = k;

    while ((k - prevk) > 1)
    {

        mid = prevk + (k - prevk) / 2;
        if (ok(mid) > ok(k))
            prevk = mid;
        else
            k = mid;
    }

    std::cout << prevk << std::endl;
    // int x = -1;
    // int z = 100;
    // for (int b = z; b >= 1; b /= 2)
    // {
    //     std::cout << "???" << std::endl;
    //     while (ok(x + b) < ok(x + b + 1))
    //         x += b;
    // }
    // int k = x + 1;
    // std::cout << k;

    return 0;
}