#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>

#define ULL unsigned long long
#define LL long long
#define LD long double

struct Ciag
{
    char *dane;
    ULL pojemnosc;
    ULL rozmiar;

    inline ~Ciag();
    inline static Ciag wczytaj(const char = '\n');
};

class Liczba
{
public:
    inline Liczba(const Ciag &);
    inline Liczba(const Liczba &);
    inline Liczba(ULL);
    inline ~Liczba();

    inline bool operator<(const Liczba &);
    inline bool operator<=(const Liczba &);
    inline bool operator>=(const Liczba &);

    inline void pomnoz(Liczba &);
    inline void odjemnij(Liczba &);
    inline void modulo(Liczba &);
    inline void podziel_przez_dwa();

    inline bool jestParzysta();
    inline bool jestZero();

    inline ULL konwertuj();

private:
    Ciag cyfry;

    inline void zrownaj_rozmiar();
};

int main()
{
    Ciag c = Ciag::wczytaj();
    std::cout << c.dane << std::endl;
    return 0;
}

inline Ciag::~Ciag()
{
    delete[] dane;
}
inline Ciag Ciag::wczytaj(const char delimiter)
{
    Ciag ciag;
    ciag.pojemnosc = 10;
    ciag.dane = new char[ciag.pojemnosc];

    std::cin >> ciag.dane[0];
    std::cin.getline(ciag.dane + 1, ciag.pojemnosc - 1, delimiter);

    ciag.rozmiar = std::cin.gcount();
    while (std::cin.fail())
    {
        ULL stara_poj = ciag.pojemnosc;
        ciag.pojemnosc <<= 2;

        char *new_dane = new char[ciag.pojemnosc];
        memcpy(new_dane, ciag.dane, stara_poj);

        delete[] ciag.dane;
        ciag.dane = new_dane;

        std::cin.clear();
        std::cin.getline(ciag.dane + stara_poj - 1, ciag.pojemnosc - stara_poj + 1, delimiter);
        ciag.rozmiar = stara_poj + std::cin.gcount() - 2;
    }

    return ciag;
}
inline Liczba::Liczba(const Ciag &ciag)
{
    cyfry = ciag;
    for (size_t i = 0; i < cyfry.rozmiar / 2; i++)
    {
        const char zamiana = cyfry.dane[i] - 48;
        cyfry.dane[i] = cyfry.dane[cyfry.rozmiar - i - 1] - 48;
        cyfry.dane[cyfry.rozmiar - i - 1] = zamiana;
    }

    if (cyfry.rozmiar & 1)
        cyfry.dane[cyfry.rozmiar] -= 48;
}
inline Liczba::Liczba(ULL liczba)
{
    ULL reszta = liczba;

    while (reszta > 0)
    {
        reszta /= 10;
        cyfry.rozmiar++;
    }

    cyfry.pojemnosc = cyfry.rozmiar;
    cyfry.dane = new char[cyfry.pojemnosc];

    ULL i{};
    while (liczba > 0)
    {
        cyfry.dane[i] = liczba % 10;
        liczba /= 10;
        i++;
    }
}
inline Liczba::Liczba(const Liczba &liczba)
{
    cyfry.rozmiar = liczba.cyfry.rozmiar;
    cyfry.pojemnosc = liczba.cyfry.pojemnosc;

    cyfry.dane = new char[cyfry.pojemnosc];
    memcpy(cyfry.dane, liczba.cyfry.dane, cyfry.rozmiar);
}

inline Liczba::~Liczba() { delete[] cyfry.dane; }

inline bool Liczba::operator<(const Liczba &liczba)
{
    if (cyfry.rozmiar != liczba.cyfry.rozmiar)
        return cyfry.rozmiar < liczba.cyfry.rozmiar;

    for (LL i = cyfry.rozmiar - 1; i > 0; i--)
    {
        if (cyfry.dane[i] == liczba.cyfry.dane[i])
            continue;
        return cyfry.dane[i] < liczba.cyfry.dane[i];
    }

    return cyfry.dane[0] < liczba.cyfry.dane[0];
}

inline bool Liczba::operator<=(const Liczba &liczba)
{
    if (cyfry.rozmiar != liczba.cyfry.rozmiar)
        return cyfry.rozmiar < liczba.cyfry.rozmiar;

    for (LL i = cyfry.rozmiar - 1; i > 0; i--)
    {
        if (cyfry.dane[i] == liczba.cyfry.dane[i])
            continue;
        return cyfry.dane[i] <= liczba.cyfry.dane[i];
    }

    return cyfry.dane[0] <= liczba.cyfry.dane[0];
}

inline bool Liczba::operator>=(const Liczba &liczba)
{
    if (cyfry.rozmiar != liczba.cyfry.rozmiar)
        return cyfry.rozmiar > liczba.cyfry.rozmiar;

    for (LL i = cyfry.rozmiar - 1; i > 0; i--)
    {
        if (cyfry.dane[i] == liczba.cyfry.dane[i])
            continue;
        return cyfry.dane[i] >= liczba.cyfry.dane[i];
    }

    return cyfry.dane[0] >= liczba.cyfry.dane[0];
}

inline void Liczba::pomnoz(Liczba &liczba)
{
    const ULL rozmiar = cyfry.rozmiar + liczba.cyfry.rozmiar;
    char *buffer = new char[rozmiar]{0};

    for (ULL i = 0; i < liczba.cyfry.rozmiar; i++)
    {
        char nadmiar = 0;
        for (ULL j = 0; j < cyfry.rozmiar; j++)
        {
            buffer[i + j] += cyfry.dane[j] * liczba.cyfry.dane[i] + nadmiar;

            if (buffer[i + j] > 9)
            {
                nadmiar = buffer[i + j] / 10;
                buffer[i + j] %= 10;
            }
            else
                nadmiar = 0;
        }

        if (nadmiar)
            buffer[i + cyfry.rozmiar] += nadmiar;
    }

    cyfry.rozmiar = rozmiar;

    if (cyfry.pojemnosc < cyfry.rozmiar)
    {
        cyfry.pojemnosc = cyfry.rozmiar;

        delete[] cyfry.dane;
        cyfry.dane = buffer;
    }
    else
    {
        memcpy(cyfry.dane, buffer, cyfry.rozmiar);
        delete[] buffer;
    }

    zrownaj_rozmiar();
}
