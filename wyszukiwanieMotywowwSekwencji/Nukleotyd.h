#pragma once
#include <iostream>
#include <string>
using namespace std;

class Nukleotyd
{
public:
	char znak;
	int nr_w_oryginalnej_sekw;
	int wiarygodnosc;
	Nukleotyd(char znak, int nr, int wiar);

};

