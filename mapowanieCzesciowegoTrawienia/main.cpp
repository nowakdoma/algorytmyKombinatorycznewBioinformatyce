#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include "zbiorA.h"
#include <chrono>

using namespace std;

int main()
{
    string tmp;

    string plik;
    cout << "Podaj nazwe pliku: ";
    cin >> plik;


    ifstream file(plik);
    getline(file, tmp);
    file.close();

    auto s1 = chrono::steady_clock::now();
        zbiorA A(tmp);

        if (A.sprawdz_liczbe_ciec())
            A.stworz_mape();

    auto e1 = chrono::steady_clock::now();

    cout<<"Czas: " << chrono::duration_cast<chrono::milliseconds>(e1 - s1).count() << " ms" << endl;

}
