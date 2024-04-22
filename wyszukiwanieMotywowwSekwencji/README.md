# Uruchomienie

## Z Visual Studio:

1. Dodaj pliki do nowego projektu w Visual Studio.
2. Skompiluj i uruchom plik `main.cpp`.

## Z wiersza poleceń:

1. Skompiluj wykorzystując polecenie:
    ```bash
    clang++ main.cpp Graf.cpp Nukleotyd.cpp Sekwencja.cpp Wierzcholek.cpp -o przyklad
    ```
2. Uruchom program:
    ```bash
    ./przyklad
    ```


## Po uruchomieniu 
Podaj:
  * próg wiarygodności, nukleotydy dla których wiarygodność będzie poniżej podanego progu zostaną usunięte z sekwencji
  * długość podciągów z zakresu [4, 9]
  * nazwę pliku .fasata np. ```przykladFASTA```
  * nazwę pliku .qual np. ```przykladQUAL```

# Wynik
W konsoli zostanie wypisany znaleziony motyw oraz miejsca na których on występuje.
  ### Dla ```przykladFASTA.fasta```, ```przykladQUAL.qual```, progu 10 oraz długości podciągu 5
  ```
  Znaleziony motyw: GCGTA
   W sekwencji: 1 na 32 pozycji
   W sekwencji: 2 na 32 pozycji
   W sekwencji: 3 na 33 pozycji
   W sekwencji: 4 na 32 pozycji
   W sekwencji: 5 na 33 pozycji
  ```

