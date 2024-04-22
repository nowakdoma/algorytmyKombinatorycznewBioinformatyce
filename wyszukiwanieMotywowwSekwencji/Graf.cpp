#include "Graf.h"

void Graf::dodad_wiercholek(int id, int nr_sekwencji, int pozycja_poczatkowego_nukleotydu, string sekwencja_oligo)
{
	Wierzcholek wierzcholek(id, nr_sekwencji, pozycja_poczatkowego_nukleotydu, sekwencja_oligo);
	lista_wierzcholkow.push_back(wierzcholek);
}

void Graf::stworz_graf()
{
	//O(n^2) n - liczba wierzcholkow 
	bool znaleziony = false;
	for (int i = 0; i < lista_wierzcholkow.size(); i++) {
		for (int j = (i + 1); j < lista_wierzcholkow.size(); j++) {
			
			if (lista_wierzcholkow[i].nr_sekwencji != lista_wierzcholkow[j].nr_sekwencji && 
				abs(lista_wierzcholkow[i].pozycja_poczatkowego_nukleotydu - lista_wierzcholkow[j].pozycja_poczatkowego_nukleotydu) <= (lista_wierzcholkow[i].sekwencja_oligo.size() * 10) &&
				lista_wierzcholkow[i].sekwencja_oligo == lista_wierzcholkow[j].sekwencja_oligo) {

			//dodanie krawedzi miedzy tymi wierzcholkami
				lista_wierzcholkow[i].lista_polaczen.push_back(&lista_wierzcholkow[j]);
				lista_wierzcholkow[j].lista_polaczen.push_back(&lista_wierzcholkow[i]);
			//update dla obu wierzcholkow zbioru nr sekwencji z ktorymi sa polaczone
			// jesli maksymalna liczba elementow w secie przed updatem to 3 z³o¿onosc dodania elementu do setu to log(wielkosc setu) wiec wiedzac ze tu rozmiar nie moze byc wiekszy niz 3 jest to stala O(1)
				lista_wierzcholkow[i].updade(lista_wierzcholkow[j].nr_sekwencji);
				lista_wierzcholkow[j].updade(lista_wierzcholkow[i].nr_sekwencji);
			//jesli wierzcholek ma 4 elementy w zbiorze to jest wierzcholkiem znajdujacym sie w gwiadzie i nie ma potrzeby dalej tworzyc grafu
			//poniewaz zalezy nam na jednym z mozliwych rozwiazan
				if (lista_wierzcholkow[i].czy_gwiazda()) {
					cout << "Znaleziony motyw: " << lista_wierzcholkow[i].sekwencja_oligo << endl;
					cout << " W sekwencji: " << lista_wierzcholkow[i].nr_sekwencji << " na " << lista_wierzcholkow[i].pozycja_poczatkowego_nukleotydu << " pozycji" << endl;
					for (auto polaczone : lista_wierzcholkow[i].lista_polaczen) {
						cout << " W sekwencji: " << polaczone->nr_sekwencji << " na " << polaczone->pozycja_poczatkowego_nukleotydu << " pozycji" << endl;

					}
					znaleziony = true;
				}
				if (lista_wierzcholkow[j].czy_gwiazda() && znaleziony == false) {
					cout << "Znaleziony motyw: " << lista_wierzcholkow[j].sekwencja_oligo << endl;
					cout << " W sekwencji: " << lista_wierzcholkow[j].nr_sekwencji << " na " << lista_wierzcholkow[j].pozycja_poczatkowego_nukleotydu << " pozycji" << endl;
					for (auto polaczone : lista_wierzcholkow[j].lista_polaczen) {
						cout << " W sekwencji: " << polaczone->nr_sekwencji << " na " << polaczone->pozycja_poczatkowego_nukleotydu << " pozycji" << endl;
					}
					znaleziony = true;
				}
			}

			if (znaleziony)
				break;
		}
		if (znaleziony)
			break;
	}
	if (znaleziony == false) {
		cout << "Nie znaleziono motywu";
	}

}
