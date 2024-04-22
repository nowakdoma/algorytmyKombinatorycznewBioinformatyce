#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Sekwencja.h"
#include "Wierzcholek.h"
#include <cmath>

using namespace std;


class Graf
{
	vector<Wierzcholek> lista_wierzcholkow;
public:
	void dodad_wiercholek(int id,
		int nr_sekwencji,
		int pozycja_poczatkowego_nukleotydu,
		string sekwencja_oligo);
	void stworz_graf();
};

