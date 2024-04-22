#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

class zbiorA
{
	vector<int> zbior;
	vector<bool> dostepnosc_elementow_zbioru;
	vector<int> mapa;
	vector<int> nowo_dodane_sumy;
	vector<int> sumy_z_poziomow[15];
	vector<int> mapakoncowa;
	int liczba_ciec;
	int wielkosc_mapy;
	int jest;
	void szukaj(int aktualny_poziom);
	bool czy_warto_to_dodac_i_kontynulowac(int val);
public:
	zbiorA(string tekst);
	bool sprawdz_liczbe_ciec();
	void stworz_mape();
	int gdzie_dostepny_w_zbiorze(int value);
	void dodaj_z_powrotem(int value);
	vector<int> zwroc_mape();


};

