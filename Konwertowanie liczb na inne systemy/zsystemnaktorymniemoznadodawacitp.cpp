#include <iostream>
#include <string>

int main()
{
    size_t wynik{0}, potega{1}, podstawa;
    size_t tmp{};
    std::string n;

    size_t cyfra{};

    std::cin >> n >> podstawa;

    // Czytamy od konca
    // Czyli jak w sensie mamy 1010 to zaczynamy od 0 pozniej 1 pozniej 0 pozniej 1
    for (long long i = n.size() - 1; i >= 0; i--)
    {
        cyfra = n[i] >= 'A' && n[i] <= 'F' ? cyfra = (n[i] - '7') : cyfra = (n[i] - '0'); // n[i] - '0' Konwertowanie ze charu w zakresie od 1 do 9 na int

        wynik = wynik + cyfra * potega;
        potega = potega * podstawa;
    }

    std::cout << wynik << std::endl;

    return 0;
}