#include <iostream>
#include <algorithm>

bool ok(int wartosc)
{
    return wartosc > 75;
}
int main()
{
    int k{1}, prevk{};

    if (ok(k))
        std::cout << k << std::endl;

    while (!ok((k <<= 1)))
        prevk = k;

    while (k - prevk > 1)
    {
        if (ok(prevk + (k - prevk) / 2))
            k = prevk + (k - prevk) / 2;
        else
            prevk = prevk + (k - prevk) / 2;
    }
    std::cout << k << std::endl;

    return 0;
}