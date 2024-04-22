#pragma once
#include "Nukleotyd.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Sekwencja
{
public:
	vector<Nukleotyd> sekwencja;
	int nr_sekwencji;
	Sekwencja(string fasta, string qual, int nr_sekw);
	void sprawdz_wiarygodnosc(int prog);
};
