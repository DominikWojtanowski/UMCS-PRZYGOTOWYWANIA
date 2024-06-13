#include <iostream>

int main()
{
    std::string tekst;
    std::string wzorzec;

    bool wystepuje;

    std::cin >> tekst >> wzorzec;
    for (size_t i = 0; i < tekst.size(); i++)
    {
        wystepuje = true;
        if (tekst[i] == wzorzec[0] && (i + wzorzec.size() <= tekst.size()))
        {
            for (size_t j = 0; j < wzorzec.size(); j++)
            {
                if (tekst[i + j] != wzorzec[j])
                {
                    wystepuje = false;
                    break;
                }
            }
            if (wystepuje)
                std::cout << i << " ";
        }
        else if ((i + wzorzec.size()) > tekst.size())
            break;
    }

    return 0;
}