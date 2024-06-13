#include <iostream>



int main()
{
    int z = 100;
    int x = -1;
    for (int b = z; b >= 1; b /= 2)
    {
        while (f(x + b) < f(x + b + 1))
            x += b;
    }
    int k = x + 1;
}