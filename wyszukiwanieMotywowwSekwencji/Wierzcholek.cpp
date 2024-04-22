#include "Wierzcholek.h"


Wierzcholek::Wierzcholek(int id, int nr_sekwencji, int pozycja_poczatkowego_nukleotydu, string sekwencja_oligo) : id(id), nr_sekwencji(nr_sekwencji), pozycja_poczatkowego_nukleotydu(pozycja_poczatkowego_nukleotydu), sekwencja_oligo(sekwencja_oligo)
{
}

bool Wierzcholek::czy_gwiazda()
{
    if (z_jakimi_juz_polaczony.size() == 4) {
        return true;
    }
    return false;
}

void Wierzcholek::updade(int nr_sekw_drugiego)
{
    z_jakimi_juz_polaczony.insert(nr_sekw_drugiego);
}

