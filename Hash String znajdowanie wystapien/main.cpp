#include <iostream>
#include <string>
#include <forward_list>
#include <cstring>
#include <unordered_map>

#define ULL unsigned long long
#define LL long long
#define LD long double

struct Ciag
{
    char *dane;
    ULL rozmiar;
    ULL pojemnosc;

    inline ~Ciag() { delete[] dane; }
    static inline Ciag wczytaj(const char delimiter = '\n');
};

struct Node
{
    const char *dane;
    ULL count{};
};

class HashMap
{
    ULL size;
    std::unordered_map<const char *, ULL> *substrings_arr{nullptr};

public:
    inline HashMap(ULL);
    inline virtual ~HashMap();
    inline void addNode(const char *);
    inline ULL findNodesCount(const char *);
};

int main()
{
    HashMap hash_map(256);

    Ciag tekst = Ciag::wczytaj();
    Ciag wzorzec = Ciag::wczytaj();

    ULL wzorzec_rozmiar = wzorzec.rozmiar;

    char *dane = new char[wzorzec_rozmiar + 1];
    dane[wzorzec_rozmiar] = '\0';

    // std::cout << tekst.dane << ", " << wzorzec.dane << std::endl;

    for (size_t i = 0; i <= tekst.rozmiar - wzorzec_rozmiar; i++)
    {
        strncpy(dane, tekst.dane + i, wzorzec_rozmiar);

        hash_map.addNode(dane);
    }

    std::cout << hash_map.findNodesCount(wzorzec.dane) << std::endl;
    delete[] dane;

    return 0;
}

inline Ciag Ciag::wczytaj(const char delimiter)
{
    Ciag ciag;
    ciag.pojemnosc = 10;
    ciag.dane = new char[ciag.pojemnosc]; // 9 elementow wraz z koncem tablicy '\0'
    std::cin >> ciag.dane[0];
    std::cin.getline(ciag.dane + 1, ciag.pojemnosc - 1, delimiter);

    ciag.rozmiar = std::cin.gcount(); // ile wczytalem dotychczas
    while (std::cin.fail())
    {
        ULL stara_poj = ciag.pojemnosc;
        ciag.pojemnosc <<= 2; // mnozymy przez 4

        char *nowe_dane = new char[ciag.pojemnosc];
        memcpy(nowe_dane, ciag.dane, stara_poj);

        delete[] ciag.dane;
        ciag.dane = nowe_dane;

        std::cin.clear(); // usuwam flage fail
        std::cin.getline(ciag.dane + stara_poj - 1, ciag.pojemnosc - stara_poj + 1, delimiter);
        ciag.rozmiar = std::cin.gcount() + stara_poj - 1 - 1;
    }

    return ciag;
}
inline HashMap::HashMap(ULL size) : size{size}
{
    substrings_arr = new std::unordered_map<const char *, ULL>[size];
}
inline HashMap::~HashMap()
{
    delete[] substrings_arr;
}
inline void HashMap::addNode(const char *dane)
{

    std::hash<std::string_view> hasher;
    ULL hash_id = hasher(dane) % size;

    substrings_arr[hash_id][dane]++;
}
inline ULL HashMap::findNodesCount(const char *dane)
{
    std::hash<std::string_view> hasher;
    ULL hash_id = hasher(dane) % size;
    ULL count_of_nodes_found{};

    for (auto it = substrings_arr[hash_id].cbegin(); it != substrings_arr[hash_id].cend(); it++)
    {
        if (strcmp((*it).first, dane) == 0)
            return (*it).second;
    }

    return count_of_nodes_found;
}