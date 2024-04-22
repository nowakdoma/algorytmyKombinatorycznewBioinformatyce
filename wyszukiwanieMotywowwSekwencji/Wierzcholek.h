#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Sekwencja.h"

using namespace std;

class Wierzcholek
{
public:
	int id;
	int nr_sekwencji;
	int pozycja_poczatkowego_nukleotydu;
	string sekwencja_oligo;
	set<int> z_jakimi_juz_polaczony;
	vector<Wierzcholek*> lista_polaczen;

	Wierzcholek(int id,
		int nr_sekwencji,
		int pozycja_poczatkowego_nukleotydu,
		string sekwencja_oligo);
	
	bool czy_gwiazda();
	void updade(int nr_sekw_drugiego);

};

