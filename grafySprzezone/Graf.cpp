#include "Graf.h"


void Graf::wczytywanie(string nazwa)
{
	fstream plik;
	plik.open(nazwa, ios::in);
	if (!plik.good()) {
		cout << "Blad wczytania pliku" << endl;
		plik.close();
	}

	string dane;

	liczbawierzcholkow = 0;

	while (getline(plik, dane)) {
		liczbawierzcholkow++;
		string del = " ";
		int start = 0;
		int koniec = dane.find(del);
		int licznik = 0;
		string temp;
		int indeks = 0;
		{
			while (koniec != -1) {
				temp = dane.substr(start, koniec - start);
				if (licznik == 0) {
					indeks = stoi(temp);
				}
				else {
					graf[indeks].push_back(stoi(temp));
				}
				start = koniec + del.size();
				koniec = dane.find(del, start);
				licznik++;

			}
			temp = dane.substr(start, koniec - start);
			if (licznik == 0) {
				indeks = stoi(temp);
			}
			else {
				graf[indeks].push_back(stoi(temp));
			}
		}

	}

	for (int i = 0; i < liczbawierzcholkow; i++) {
		sort(graf[i].begin(), graf[i].end());
	}



}

void Graf::zapisywanie()
{
	fstream plik;
	plik.open("wynik.txt", ios::out);
	if (!plik.good()) {
		cout << "Blad wczytania pliku" << endl;
		plik.close();
	}

	for (int i = 0; i < lwierzH; i++) {
			plik << i;
			for (int j = 0; j < H[i].size(); j++) {
				plik << " " << H[i][j] ;
			}
			plik << endl;
		
	}
}


bool Graf::czysprzezony()
{

//sprawdzenie czy jest 1-grafem
	for (int i = 0; i < liczbawierzcholkow; i++) {
		for (int j = 1; j < graf[i].size(); j++) {
			int k = j - 1;
			if (graf[i][j] == graf[i][k]) {
				//cout << "Graf nie jest 1-grafem" << endl;
				return false;
			}
		}
	}


//pozostale warunki
	for (int i = 0; i < (liczbawierzcholkow - 1); i++) {
		for (int j = (i + 1); j < liczbawierzcholkow; j++) {
			if (graf[i].size() > 0 && graf[j].size() > 0) {

				if (graf[i][0] == graf[j][0]) {
					if (graf[i].size() != graf[j].size()) {
						return false;
					}

					for (int k = 0; k < graf[i].size(); k++) {
						if (graf[i][k] != graf[j][k]) {
							return false;
						}

					}
				}

				else {
					for (int k = 0; k < graf[i].size(); k++) {
						for (int l = 0; l < graf[j].size(); l++) {
							if (graf[i][k] == graf[j][l])
								return false;
						}
					}
				}
			}
		}

	}
	return true;


}


void Graf::przeksztalcenie()
{
	int tabpomocnicza[20][3];
//tablica pomocnicza tworzaca zbior rozlacnzych lukow
	for (int i = 0; i < 20; i++) {
		
		int k = (i + 1) * 2;
		int j = k - 1;

		if (i < liczbawierzcholkow) {
			tabpomocnicza[i][0] = j;
			tabpomocnicza[i][1] = k;
		}
		else {
			tabpomocnicza[i][0] = -1;
			tabpomocnicza[i][1] = -1;
		}
		//jesli tab[i][2] = 0 to znaczy ze przy przeksztalceniu nie byla jeszcze zmieniana wartosc tab[i][0]
		tabpomocnicza[i][2] = 0;
	}

//do poznijeszego przeindeksowania

	int przedost = liczbawierzcholkow - 1;
	int najwiekszywierz = tabpomocnicza[przedost][1];


//polaczenie lukow wedlug grafu graf

		for (int i = 0; i < liczbawierzcholkow; i++) {
			for (int k : graf[i]) {
				if (tabpomocnicza[k][2] == 0) {
					tabpomocnicza[k][0] = tabpomocnicza[i][1];
					tabpomocnicza[k][2] = 1;
				}
				else {
					tabpomocnicza[i][1] = tabpomocnicza[k][0];
				}
			}
		}




//przeindeksowanie
	int licznik = 0;
	for (int i = 1; i <= najwiekszywierz; i++) {
		bool zmiana = false;
		for (int j = 0; j < liczbawierzcholkow; j++) {
			if (tabpomocnicza[j][0] == i) {
				tabpomocnicza[j][0] = licznik;
				zmiana = true;
			}
			if (tabpomocnicza[j][1] == i) {
				tabpomocnicza[j][1] = licznik;
				zmiana = true;
			}
		}
		if (zmiana)
			licznik++;
	}


	lwierzH = licznik;

//wpisanie do grafu wynikowego H
	for (int i = 0; i < liczbawierzcholkow; i++) {
		int j = tabpomocnicza[i][0];
		int k = tabpomocnicza[i][1];
		H[j].push_back(k);
	}



}

bool Graf::czyliniowy()
{
	for (int i = 0; i < lwierzH; i++) {
		sort(H[i].begin(), H[i].end());
	}


	for (int i = 0; i < lwierzH; i++) {
		for (int j = 1; j < H[i].size(); j++) {
			int k = j - 1;
			if (H[i][j] == H[i][k]) {
				//cout << "Graf nie jest 1-grafem" << endl;
				return false;
			}
		}
	}
	return true;
}

