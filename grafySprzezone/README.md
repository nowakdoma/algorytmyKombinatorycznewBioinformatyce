# Uruchomienie

## Z Visual Studio:

1. Dodaj pliki do nowego projektu w Visual Studio.
2. Skompiluj i uruchom plik `main.cpp`.

## Z wiersza poleceń:

1. Skompiluj wykorzystując polecenie:
    ```bash
    clang++ main.cpp graf.cpp -o przyklad
    ```
2. Uruchom program:
    ```bash
    ./przyklad
    ```


## Po uruchomieniu 
  Podaj nazwę pliku z grafem np. ```przykladLiniowy.txt```

# Format pliku z grafem 
* Reprezentacja grafu w formie listy następników
* Pierwsza wartość w rzędzie to indeks wierzchołka, następne odzielane spacją to jego następniki
* Na końcu pliku nie może znajdować się spacja
  ### ```przykladLiniowy.txt```
  ```
  0 0 1
  1 2 3
  2 4 5
  3 6 7
  4 8 9
  5 10
  6 8 9
  7 6 7
  8 5 4
  9 3 2
  10 0 1
  ```
  ### ```przykladNieliniowy.txt```
  ```
  0 5 6 7 10
  1 2 3
  2 1 4 9
  3 1 4 9
  4 2 3
  5 8
  6 0
  7 1 4 9
  8
  9 5 6 7 10
  10 2 3
  ```
# Wynik
W konsoli zostanie wypisane czy graf jest liniowy / sprzężony, ale nie liniowy / nie jest sprzężony. Jeżeli graf jest sprzężony to zostanie wygenerowany plik wynik.txt zawierający oryginalny graf z którego on powstał.
