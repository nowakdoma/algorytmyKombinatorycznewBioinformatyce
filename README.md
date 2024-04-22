# Rozwiązania zadań z Algorytmy Kombinatoryczne w Bioinformatyce (rok akademicki 2022/2023)

Repozytorium zawiera rozwiązania zadań z przedmiotu "Algorytmy Kombinatoryczne w Bioinformatyce" z roku akademickiego 2022/2023. Poniżej znajduje się lista podfolderów zawierających rozwiązania poszczególnych zadań.

## Zadania

1. [Grafy Sprzężone](grafySprzezone/)
   * wczytanie grafu skierowanego
   * sprawdzenie, czy wczytany graf jest grafem sprzężonym
   * sprawdzenie, czy jest grafem liniowym
   * jeśli graf jest grafem sprzężonym, przekształcenie go w jego graf oryginalny (H)
   * zapisanie grafu wynikowego H
   
3. [Wyszukiwanie Motywów w Sekwencjach](wyszukiwanieMotywowwSekwencji/)
   * wczytanie instancji
   * usunięcie z sekwencji nukleotydów o wiarygodności poniżej progu podawnego po uruchomieniu programu
   * utworzenie grafu z wierzchołkami odpowiadającymi wszystkim kilkuliterowym (4 - 9) podciągom sekwencji po powyższej operacji, długość podciągu podawana przez użytkownika
   * połączenie wierzchołków odpowiadających tym samym podciągom w róznych sekwencjach nieskierowanymi krawędziami, jeżeli różnica w pozycjach podciągów wewnątrz sekwencji nie jest większa niż dziesięciokrotność długości podciągu
   * wyszukanie w grafie w sposób heurystyczny kliki lub struktury zbliżonej do kliki, w której każda sekwencja wejściowa będzie reprezentowana dokładnie jednym wierzchołkiem
   * wypisanie rezultatu na wyjściu
   
4. [Mapowanie Częściowego Trawienia](mapowanieCzesciowegoTrawienia/)
   * wczytanie instancji (multizbioru A)
   * skonstruowanie mapy restrykcyjnej zgodnej z podanym multizbiorem
   * wypisanie rezultatu na wyjściu w sposób czytelny dla użytkownika


