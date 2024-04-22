# Uruchomienie

## Z Visual Studio:

1. Dodaj pliki do nowego projektu w Visual Studio.
2. Skompiluj i uruchom plik `main.cpp`.

## Z wiersza poleceń:

1. Skompiluj wykorzystując polecenie:
    ```bash
    clang++ main.cpp zbiorA.cpp -o przyklad
    ```
2. Uruchom program:
    ```bash
    ./przyklad
    ```


## Po uruchomieniu 
  Podaj nazwę pliku z grafem np. ```poprawnyPrzyklad.txt```

# Format pliku z grafem 
* Długości fragmentów otrzymanych metodą częściowego trawienia oddzielone spacją
  ### ```poprawnyPrzyklad.txt```
  ```
  2 6 6 7 8 8 8 9 14 14 14 15 16 20 22 22 23 28 29 30 37
  ```

# Wynik
W konsoli zostanie wypisana utworzona mapa lub komunikat o niepoprawności zbioru A oraz czas otrzymania wyniku. 
  ### Dla ```poprawnyPrzyklad.txt```
  ```
  Znaleziona mapa: 7 2 6 8 6 8
  Czas: 1 ms
  ```
  ### Dla ```brakMapyPrzyklad.txt```
  ```
  Brak mapy
  Czas: 10 ms
  ```
