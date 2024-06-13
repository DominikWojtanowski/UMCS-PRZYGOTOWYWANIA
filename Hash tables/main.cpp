#include <iostream>
#include <cstring>
#include <string_view>

#define ULL unsigned long long

struct Ciag
{
    char *dane;
    ULL rozmiar;
    ULL pojemnosc;

    inline void przeczytaj();
    inline void readHash();
    static inline Ciag wczytaj(const char = '\n');
};

struct Node
{
    Node *nextNode{nullptr};
    Ciag ciag;

    inline void przeczytaj();
    inline void readHash();

    Node() : nextNode(nullptr) {}

    ~Node()
    {
        delete[] ciag.dane;
    }
};

class HashMap
{
public:
    inline HashMap(const int size);
    inline ~HashMap();
    inline void addNode(Node *) const;
    inline Node *findNode(Ciag *) const;
    inline Node &getNode(ULL hashId, char *eventualData) const;

    friend std::ostream &operator<<(std::ostream &os, const HashMap &hashMap)
    {
        for (size_t i = 0; i < hashMap.arr_size; i++)
        {
            Node *tmp = hashMap.arr[i];

            while (tmp)
            {
                os << tmp->ciag.dane << " -> ";
                tmp = tmp->nextNode;
            }

            std::cout << "\n";
        }
        return os;
    };

private:
    ULL arr_size;
    Node **arr{nullptr};
};

int main()
{
    HashMap hashMap(10);
    Node *nodeOne = new Node();
    Node *nodeTwo = new Node();
    nodeOne->ciag = Ciag::wczytaj();
    nodeTwo->ciag = Ciag::wczytaj();

    hashMap.addNode(nodeOne);
    hashMap.addNode(nodeTwo);

    Ciag ciag2 = Ciag::wczytaj();

    std::cout << hashMap << "\n";

    Node *findNode = hashMap.findNode(&ciag2);
    if (findNode)
        std::cout << "znalazlem";
    else
        std::cout << "nieznalazlem";

    delete nodeOne;
    delete nodeTwo;
    return 0;
}

inline Ciag Ciag::wczytaj(const char koniec_str)
{
    Ciag ciag;
    ciag.pojemnosc = 10; // defaultowa pojemnosc
    ciag.dane = new char[ciag.pojemnosc];

    std::cin >> ciag.dane[0];
    std::cin.getline(ciag.dane + 1, ciag.pojemnosc - 1, koniec_str);
    ciag.rozmiar = std::cin.gcount(); // ilosc wczytanych znakow

    while (std::cin.fail())
    {
        ULL stara_poj = ciag.pojemnosc;
        ciag.pojemnosc <<= 2;

        char *newData = new char[ciag.pojemnosc];
        memcpy(newData, ciag.dane, stara_poj);

        delete[] ciag.dane;
        ciag.dane = newData;

        std::cin.clear();
        std::cin.getline(ciag.dane + stara_poj - 1, ciag.pojemnosc - stara_poj + 1, koniec_str);
        ciag.rozmiar = stara_poj - 1 + std::cin.gcount() - 1;
    }

    return ciag;
}

inline void Ciag::przeczytaj()
{
    std::cout << dane << "\n";
}

inline void Node::przeczytaj()
{
    ciag.przeczytaj();
}

inline void Ciag::readHash()
{
    std::cout << std::hash<std::string_view>{}(dane) << "\n";
}

inline void Node::readHash()
{
    ciag.readHash();
}

inline HashMap::HashMap(int size) : arr_size{size}
{
    arr = new Node *[size]
    { nullptr };
}

HashMap::~HashMap()
{

    delete[] arr; // Zwolnienie tablicy wskaźników na listy
}

inline void HashMap::addNode(Node *node) const
{
    ULL index = std::hash<std::string_view>{}(node->ciag.dane);
    ULL hashIndex = index % arr_size;

    Node *currNode = arr[hashIndex];
    if (currNode)
    {
        while (currNode->nextNode)
            currNode = currNode->nextNode;
        currNode->nextNode = node;
    }
    else
        arr[hashIndex] = node;
}

inline Node *HashMap::findNode(Ciag *ciag) const
{
    ULL hashindex = std::hash<std::string_view>{}(ciag->dane) % arr_size;

    Node *currNode = arr[hashindex];

    while (currNode)
    {
        if (strcmp(currNode->ciag.dane, ciag->dane) == 0)
            return currNode;
        currNode = currNode->nextNode;
    }
    return nullptr;
}
