#include <cstring>
#include <iostream>

#define ULL unsigned long long

struct Ciag
{
    char *dane;
    ULL rozmiar;
    ULL pojemnosc;

    static inline Ciag wczytaj(const char delimiter = '\n');
};

class Liczba
{
public:
    inline Liczba(const Ciag ciag);
    inline Liczba(ULL liczba);
    inline Liczba(Liczba &liczba);
    inline ~Liczba();

    inline bool operator<(Liczba &liczba);
    inline bool operator>=(Liczba &liczba);
    inline bool operator<=(Liczba &liczba);

    inline void pomnoz(Liczba &liczba);
    inline void odejmij(Liczba &liczba);
    inline void modulo(Liczba &liczba);
    inline void podziel_przez_2();

    inline bool parzysta() const;
    inline bool zero() const;

    inline ULL konwertuj() const;
    Ciag cyfry;

private:
    inline void zrownaj_rozmiar();
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    // int n;
    // std::cin >> n;
    Liczba d(Ciag::wczytaj(' '));
    Liczba a(Ciag::wczytaj(' '));

    d.odejmij(a);
    std::cout << d.cyfry.dane << std::endl;
    // Liczba m(Ciag::wczytaj(' '));
    // for (int i = 0; i < n; i++) {
    //   Liczba c(Ciag::wczytaj(' '));
    //   Liczba msg(1);
    //   Liczba p(d);

    //   while (!p.zero()) {
    //     if (!p.parzysta()) {
    //       msg.pomnoz(c);
    //       msg.modulo(m);
    //     }

    //     p.podziel_przez_2();
    //     c.pomnoz(c);
    //     c.modulo(m);
    //   }

    //   Ciag s = Ciag::wczytaj();
    //   Liczba s_rozmiar(s.rozmiar);
    //   msg.modulo(s_rozmiar);
    //   const ULL indeks_graniczny = msg.konwertuj();

    //   std::cout.write(s.dane + indeks_graniczny, s.rozmiar - indeks_graniczny)
    //       .write(s.dane, indeks_graniczny)
    //       .put(' ');

    //   delete[] s.dane;
    // }
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
inline Liczba::Liczba(const Ciag ciag)
{
    cyfry = ciag;

    for (ULL i = 0; i < cyfry.rozmiar / 2; i++)
    {

        const char zamiana = cyfry.dane[i] - 48;
        cyfry.dane[i] = cyfry.dane[cyfry.rozmiar - i - 1] - 48;
        cyfry.dane[cyfry.rozmiar - i - 1] = zamiana;
    }

    if (cyfry.rozmiar & 1)
        cyfry.dane[cyfry.rozmiar / 2] -= 48;
}

inline Liczba::Liczba(ULL liczba)
{
    ULL reszta = liczba;
    cyfry.rozmiar = 0;
    while (reszta > 0)
    {
        cyfry.rozmiar++;

        reszta /= 10;
    }

    cyfry.pojemnosc = cyfry.rozmiar;
    cyfry.dane = new char[cyfry.pojemnosc];

    int i = 0;
    while (liczba > 0)
    {
        cyfry.dane[i] = liczba % 10;

        liczba /= 10;

        i++;
    }
}

inline Liczba::Liczba(Liczba &liczba)
{
    cyfry.rozmiar = liczba.cyfry.rozmiar;
    cyfry.pojemnosc = liczba.cyfry.pojemnosc;

    cyfry.dane = new char[cyfry.pojemnosc];
    memcpy(cyfry.dane, liczba.cyfry.dane, cyfry.rozmiar);
}

inline Liczba::~Liczba() { delete[] cyfry.dane; }

inline bool Liczba::operator<(Liczba &liczba)
{
    if (cyfry.rozmiar != liczba.cyfry.rozmiar)
        return cyfry.rozmiar < liczba.cyfry.rozmiar;

    for (ULL i = cyfry.rozmiar - 1; i > 0; i--)
    {
        if (cyfry.dane[i] == liczba.cyfry.dane[i])
            continue;

        return cyfry.dane[i] < liczba.cyfry.dane[i];
    }

    return cyfry.dane[0] < liczba.cyfry.dane[0];
}

inline bool Liczba::operator<=(Liczba &liczba)
{
    if (cyfry.rozmiar != liczba.cyfry.rozmiar)
        return cyfry.rozmiar < liczba.cyfry.rozmiar;

    for (ULL i = cyfry.rozmiar - 1; i > 0; i--)
    {
        if (cyfry.dane[i] == liczba.cyfry.dane[i])
            continue;

        return cyfry.dane[i] < liczba.cyfry.dane[i];
    }

    return cyfry.dane[0] <= liczba.cyfry.dane[0];
}

inline bool Liczba::operator>=(Liczba &liczba)
{
    if (cyfry.rozmiar != liczba.cyfry.rozmiar)
        return cyfry.rozmiar > liczba.cyfry.rozmiar;

    for (ULL i = cyfry.rozmiar - 1; i > 0; i--)
    {
        if (cyfry.dane[i] == liczba.cyfry.dane[i])
            continue;

        return cyfry.dane[i] > liczba.cyfry.dane[i];
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

inline void Liczba::odejmij(
    Liczba &liczba) // Oczekuję się, że pod *this jest większa liczba
{
    for (ULL i = 0; i < liczba.cyfry.rozmiar; i++)
    {
        if (cyfry.dane[i] < liczba.cyfry.dane[i])
        {
            cyfry.dane[i] += 10;
            cyfry.dane[i + 1] -= 1;
        }

        cyfry.dane[i] -= liczba.cyfry.dane[i];
    }

    for (size_t i = 0; i < cyfry.rozmiar; i++)
        std::cout << (int)cyfry.dane[i] << ", ";

    zrownaj_rozmiar();
}

inline void Liczba::modulo(Liczba &liczba)
{
    Liczba dwa(2);
    Liczba k(liczba);

    while (k < *this)
        k.pomnoz(dwa);

    while (*this >= liczba)
    {
        if (k <= *this)
            odejmij(k);
        else
            k.podziel_przez_2();
    }
}

inline void Liczba::podziel_przez_2()
{
    cyfry.dane[0] /= 2;

    for (ULL i = 1; i < cyfry.rozmiar; i++)
    {
        if (cyfry.dane[i] & 1)
        {
            cyfry.dane[i - 1] += 5;
        }

        cyfry.dane[i] /= 2;
    }

    zrownaj_rozmiar();
}

inline bool Liczba::parzysta() const { return !(cyfry.dane[0] & 1); }

inline bool Liczba::zero() const
{
    return cyfry.rozmiar == 1 && cyfry.dane[0] == 0;
}

inline ULL Liczba::konwertuj() const
{
    ULL liczba = 0;
    ULL wspolczynnik = 1;
    for (ULL i = 0; i < cyfry.rozmiar; i++)
    {
        liczba += cyfry.dane[i] * wspolczynnik;
        wspolczynnik *= 10;
    }
    return liczba;
}

inline void Liczba::zrownaj_rozmiar()
{
    while (cyfry.dane[cyfry.rozmiar - 1] == 0 && cyfry.rozmiar > 1)
        cyfry.rozmiar--;
}
