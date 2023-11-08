#include <iostream>
#include <string>

#define N 10

using namespace std;

// Funkcja kopiująca elementy tab1 do tab2
void copy_arr(int* tab1, int* tab2) {

    for (int i = 0; i < N; i++) {
        tab2[i] = tab1[i];
    }

}

int main(void) {

    // Tablica nr.1
    int tab1[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Tablica nr.2
    int *tab2 = new int[N];

    copy_arr(tab1, tab2);

    // Wyświetlanie zawartości tablicy nr.2
    for (int i = 0; i < N; i++) {
        cout << "Element o indeksie [" << i << "] tablicy nr.2 = " << tab2[i] << endl;
    }

    // Zwolnienie pamięci zarezerwowanej dla tablicy nr.2
    delete[] tab2;

    return 0;
}
