#include <iostream>
#include <cstring>

#define ULL unsigned long long
#define LL long long
#define LD long double

int *computeLPS(const char *pattern, ULL size)
{
    int *arr = new int[size];
    arr[0] = 0;
    int len{}, i{1};

    while (i < size)
    {

        if (pattern[i] == pattern[len])
            arr[i++] = ++len;
        else
        {

            if (len == 0)
                arr[i++] = 0;
            else
                len = arr[len - 1];
        }
    }

    return arr;
}

void findPattern(const char *text, const char *pattern, int *lps, ULL size_text, ULL size_pattern, ULL lps_size)
{
    ULL i{}, j{};
    while (i < size_text)
    {
        if (text[i] == pattern[j])
        {
            j++;
            i++;
            if (j == size_pattern)
                j = lps[size_pattern - 1];
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    const char *text = "AAAAABAAABA\0";
    const char *pattern = "AAAA\0";
    int *lps = computeLPS(pattern, sizeof(pattern) / sizeof(pattern[0]));

    // std::cout << strlen(text) << "\n"
    //   << sizeof(pattern) / sizeof(pattern[0]) << std::endl;

    findPattern(text, pattern, lps, strlen(text), strlen(pattern), sizeof(lps) / sizeof(lps[0]));

    return 0;
}