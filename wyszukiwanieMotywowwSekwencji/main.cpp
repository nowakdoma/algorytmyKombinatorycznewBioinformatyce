#include <iostream>
#include <fstream>
#include <string>
#include "Sekwencja.h"
#include "Graf.h"

using namespace std;

int main()
{
    int id = 0;
    int prog_wiarygodnosci;
    int dlugoosc_podciagow;
    Graf graf;      

    cout << "Podaj prog wiarygodnosci: ";
    cin >> prog_wiarygodnosci;
    cout << "Podaj dlugosc podciagow (4-9): ";
    cin >> dlugoosc_podciagow;

    std::string plikfasta, plikqual;
    std::cout << "Podaj nazwe pliku .fasta: ";
    std::cin >> plikfasta;

    std::cout << "Podaj nazwe pliku .qual: ";
    std::cin >> plikqual;

    ifstream file1(plikfasta+".fasta");
    ifstream file2(plikqual+".qual");


    string fasta, qual;
    int numer_sekwencji = -1;

    string sekwencje[5];
    string oceny[5];
//zczytanie sekwencji do tablic
    //O(n) n- liczba linijek
    while (getline(file1, fasta) && getline(file2, qual)) {
        if (fasta[0] == '>') {
            numer_sekwencji++;
            sekwencje[numer_sekwencji] = "";
            oceny[numer_sekwencji] = "";
            
        }
        else {
            sekwencje[numer_sekwencji] += fasta;
            oceny[numer_sekwencji] += qual;
            oceny[numer_sekwencji] += ' ';

        }
    }
    file1.close();
    file2.close();

//stworzenie sekwencji O(n) n - dlugosc sekwencji
    Sekwencja seq1(sekwencje[0], oceny[0], 1);
    Sekwencja seq2(sekwencje[1], oceny[1], 2);
    Sekwencja seq3(sekwencje[2], oceny[2], 3);
    Sekwencja seq4(sekwencje[3], oceny[3], 4);
    Sekwencja seq5(sekwencje[4], oceny[4], 5);



//poddanie ich ocenie wiar i usuniecie nukleotydow ponizej progu O(n) dlugosc sekwncji
    seq1.sprawdz_wiarygodnosc(prog_wiarygodnosci);
    seq2.sprawdz_wiarygodnosc(prog_wiarygodnosci);
    seq3.sprawdz_wiarygodnosc(prog_wiarygodnosci);
    seq4.sprawdz_wiarygodnosc(prog_wiarygodnosci);
    seq5.sprawdz_wiarygodnosc(prog_wiarygodnosci);


//utworzenie wierzchołkow
    //z sekwencji 1 O(n) n -dlugosc sekwencji
    for (int i = 0; i < ((seq1.sekwencja.size() - dlugoosc_podciagow) + 1); i++) {
        string oligo;
        //O(9) = O(1)
        for (int j = i; j < i + dlugoosc_podciagow; j++) {
            oligo.push_back(seq1.sekwencja[j].znak);
        }
        //O(1)
        graf.dodad_wiercholek(id, seq1.nr_sekwencji, seq1.sekwencja[i].nr_w_oryginalnej_sekw, oligo);
    }

    //z sekwencji 2
    for (int i = 0; i < ((seq2.sekwencja.size() - dlugoosc_podciagow) + 1); i++) {
        string oligo;
        for (int j = i; j < i + dlugoosc_podciagow; j++) {
            oligo.push_back(seq2.sekwencja[j].znak);
        }
        graf.dodad_wiercholek(id, seq2.nr_sekwencji, seq2.sekwencja[i].nr_w_oryginalnej_sekw, oligo);
    }
    //z sekwencji 3
    for (int i = 0; i < ((seq3.sekwencja.size() - dlugoosc_podciagow) + 1); i++) {
        string oligo;
        for (int j = i; j < i + dlugoosc_podciagow; j++) {
            oligo.push_back(seq3.sekwencja[j].znak);
        }
        graf.dodad_wiercholek(id, seq3.nr_sekwencji, seq3.sekwencja[i].nr_w_oryginalnej_sekw, oligo);
    }
    //z sekwencji 4
    for (int i = 0; i < ((seq4.sekwencja.size() - dlugoosc_podciagow) + 1); i++) {
        string oligo;
        for (int j = i; j < i + dlugoosc_podciagow; j++) {
            oligo.push_back(seq4.sekwencja[j].znak);
        }
        graf.dodad_wiercholek(id, seq4.nr_sekwencji, seq4.sekwencja[i].nr_w_oryginalnej_sekw, oligo);
    }
    //z sekwencji 5
    for (int i = 0; i < ((seq5.sekwencja.size() - dlugoosc_podciagow) + 1); i++) {
        string oligo;
        for (int j = i; j < i + dlugoosc_podciagow; j++) {
            oligo.push_back(seq5.sekwencja[j].znak);
        }
        graf.dodad_wiercholek(id, seq5.nr_sekwencji, seq5.sekwencja[i].nr_w_oryginalnej_sekw, oligo);
    }
//tworzenie grafu + sprawdzanie czy juz znaleziono motyw
    graf.stworz_graf();

}
