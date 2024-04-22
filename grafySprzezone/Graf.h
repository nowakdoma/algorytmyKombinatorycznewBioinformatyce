#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Graf
{
	vector<int> graf[20]; //graf sprawdzany
	vector<int> H[30]; //graf oryginaly
	int liczbawierzcholkow; //liczba wierzcholkow grafu sprawdzanego
	int lwierzH; //liczba wierzcholkow grafu oryginalnego

public:
	void wczytywanie(string nazwa); //funkcja wczytuj¹ca graf z pliku
	void zapisywanie(); //funkcja zapisujaca oryginalny graf do pliku
	bool czysprzezony(); //funkcja sprawdzajaca czy testowany graf jest sprzezony
	void przeksztalcenie(); //funkcja przeksztalcajaca graf testowany w oryginalny
	bool czyliniowy(); //funkcja sprawdzajaca czy testowany graf jest liniowy
};

