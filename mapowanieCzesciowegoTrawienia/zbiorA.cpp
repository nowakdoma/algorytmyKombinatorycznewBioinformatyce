#include "zbiorA.h"


zbiorA::zbiorA(string tekst)
{
	stringstream stream(tekst);
	int temp;

	while (stream >> temp) {
		zbior.push_back(temp);
	}

	vector<bool> mozliwe_z_A(zbior.size(), true);
	dostepnosc_elementow_zbioru.swap(mozliwe_z_A);
	jest = 0;
	liczba_ciec = 0;
	wielkosc_mapy = 0;


	if (zbior[0] > zbior[1] && zbior[1] > zbior[2])
		reverse(zbior.begin(), zbior.end());
}

bool zbiorA::sprawdz_liczbe_ciec()
{
	//sprawdzenie czy zbior ma mozliwa licznosc, jako ze w tresci zadania jest ze ma byc min 5 ciec a max 14 i dlatego taki rpzedzial 

	liczba_ciec = 0;

	for (int i = 4; i < 16; i++) {
		if (zbior.size() == ((i + 2) * (i + 1)) / 2) {
			liczba_ciec = i;
			wielkosc_mapy = liczba_ciec + 1;
			return true;
		}
	}

	cout << "Niepoprawna licznosc zbioru" << endl;
	return false;
}

void zbiorA::stworz_mape()
{
	//pierwszy element mapy 
	int ostatni = zbior.size() - 1;

	int pierwszy_element = zbior[ostatni] - zbior[ostatni - 1];

	int indeks = gdzie_dostepny_w_zbiorze(pierwszy_element);

	if (indeks == -1) {
		cout << "Nieprawidlowy zbior A, nie znaleziono pierwszego elementu mapy" << endl;
		return;
	}
	else {
		mapa.push_back(zbior[indeks]);
		dostepnosc_elementow_zbioru[indeks] = false;
	}

	jest = 0;

	szukaj(1);

	if (jest == 0) {
		cout << "Brak mapy" << endl;
	}

}

int zbiorA::gdzie_dostepny_w_zbiorze(int value)
{
	for (int i = 0; i < zbior.size(); i++) {
		if (zbior[i] == value && dostepnosc_elementow_zbioru[i]) {
			return i;
		}
	}
	return -1;
}

void zbiorA::dodaj_z_powrotem(int value)
{
	for (int i = 0; i < zbior.size(); i++) {
		if (zbior[i] == value && dostepnosc_elementow_zbioru[i] == false) {
			dostepnosc_elementow_zbioru[i] = true;
		}
	}

}

vector<int> zbiorA::zwroc_mape()
{
	return mapakoncowa;
}

void zbiorA::szukaj(int aktualny_poziom)
{
	/*cout << aktualny_poziom << ": ";
	for (int i = 0; i < mapa.size(); i++) {
		cout << mapa[i] << " ";
		mapakoncowa.push_back(mapa[i]);
	}
	cout << endl;*/

	vector<bool> dostepnosc_na_tym_poziomie = dostepnosc_elementow_zbioru;

	if (aktualny_poziom == wielkosc_mapy) {
		//wypisz rozw
		cout << "Znaleziona mapa: ";
		for (int i = 0; i < mapa.size(); i++) {
			cout << mapa[i] << " ";
		}

		cout << endl;
		jest = 1;
	}
	else {
		vector<bool> kopia_dostepnosci = dostepnosc_elementow_zbioru;
		int zmiana = false;
		for (int i = 0; i < zbior.size(); i++) {
			dostepnosc_elementow_zbioru = kopia_dostepnosci;
			if (dostepnosc_elementow_zbioru[i] == false) {
				continue;
			}
			if (jest == 1) {
				break;
			}
			if (czy_warto_to_dodac_i_kontynulowac(zbior[i])) {
				mapa.push_back(zbior[i]);
				zmiana = true;
				sumy_z_poziomow[aktualny_poziom] = nowo_dodane_sumy;
				szukaj(aktualny_poziom + 1);
			}
		}
		
		dodaj_z_powrotem(mapa.back());
		mapa.pop_back();
		for (int i = 0; i < sumy_z_poziomow[aktualny_poziom].size(); i++) {
			dodaj_z_powrotem(sumy_z_poziomow[aktualny_poziom][i]);
		}

		return;
	}

}

bool zbiorA::czy_warto_to_dodac_i_kontynulowac(int val)
{
	vector<bool> tmp = dostepnosc_elementow_zbioru;
	vector<int> sumy;
	int suma = accumulate(mapa.begin(), mapa.end(), 0);
	suma += val;
	int indeks_sumy = gdzie_dostepny_w_zbiorze(suma);
	if (indeks_sumy == -1) {
		return false;
	}
	tmp[indeks_sumy] = false;
	sumy.push_back(suma);

	for (int i = 0; i < mapa.size(); i++) {
		suma -= mapa[i];
		indeks_sumy = gdzie_dostepny_w_zbiorze(suma);
		if (indeks_sumy == -1) {
			return false;
		}
		tmp[indeks_sumy] = false;
		sumy.push_back(suma);
	}
	dostepnosc_elementow_zbioru.swap(tmp);
	nowo_dodane_sumy.swap(sumy);
	return true;
}
