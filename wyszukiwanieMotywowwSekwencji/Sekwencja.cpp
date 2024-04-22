#include "Sekwencja.h"

Sekwencja::Sekwencja(string fasta, string qual, int nr_sekw) : nr_sekwencji(nr_sekw)
{
	vector<int> qual_arr;
	stringstream stream(qual);
	int temp;

	while (stream >> temp) {
		qual_arr.push_back(temp);
	}


	for (int i = 0; i < fasta.size(); i++) {

		Nukleotyd nukleotyd(fasta[i], (i + 1), qual_arr[i]);
		sekwencja.push_back(nukleotyd);
	}

}

void Sekwencja::sprawdz_wiarygodnosc(int prog)
{

//from vector<Nukleotyd> sekwencja, remove all elements that element.wiarygodnosc is lower than int prog passed to the function
	/*auto new_end = remove_if(sekwencja.begin(), sekwencja.end(), [prog](const Nukleotyd& n) {
		return n.wiarygodnosc < prog;
		});

	sekwencja.erase(new_end, sekwencja.end());*/
	for (auto it = sekwencja.begin(); it != sekwencja.end();) {
		if (it->wiarygodnosc < prog) {
			it = sekwencja.erase(it);
		}
		else {
			++it;
		}
	}
}
