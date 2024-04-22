#include <iostream>
#include "Graf.h"

int main()
{
    Graf graf;

    std::string nazwapliku;
    std::cout << "Podaj nazwę pliku: ";
    std::cin >> nazwapliku;

    graf.wczytywanie(nazwapliku);

    if (!graf.czysprzezony()) {
        std::cout << "Graf nie jest sprzezony" << std::endl;
        return 0;
    }

    graf.przeksztalcenie();

    if (graf.czyliniowy())
        std::cout << "Graf jest liniowy" << std::endl;
    else
        std::cout << "Graf jest sprzezony ale nie liniowy" << std::endl;

    graf.zapisywanie();

    return 0;
}
