#include <iostream>
#include <string>

#define N 10

using namespace std;

void pointer_arithmetics(const int* tab, const int* end) {

    // Zmienne pomocnicze
    int i = 0;
    char direction = '0';

    // Pętla do poruszania się po tablicy, dopóki za nią nie wyjdziemy
    while ((tab + i) < end && (tab + i) >= tab) {

        // Wyświetlanie aktualnej pozycji w tablicy
        cout << "Twoja aktualna pozycja w tablicy to tab[" << i << "] = " << *(tab + i) << endl;

        // Wprowadzanie kierunku
        cout << "\nPodaj kierunek (+ lub -): ";
        cin >> direction;

        // Kontrola kierunku
        switch(direction) {
            case '+':
                i++;
                break;
            case '-':
                i--;
                break;
        }
    }
    // Komunikat po wyjściu za zakres tablicy
    cout << "Wyszedles poza tablice!" << endl;
}

int main(void) {

    // Tworzymy tablicę po której będziemy się poruszać
    int tab[N] = {1, 23, 444, 919, 1234, -23, 55, -18, 0, -1024};

    // Inicjujemy wskaźnik na ostatni element tablicy (by wiedzieć kiedy wyjdziemy poza jej obszar; do pętli)
    int *ptr_end = end(tab);

    // Wywołanie funkcji do poruszania się po tablicy
    pointer_arithmetics(tab, ptr_end);

    return 0;
}
