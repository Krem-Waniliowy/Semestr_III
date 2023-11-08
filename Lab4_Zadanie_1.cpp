#include <iostream>
#include <string>

#define N 10

using namespace std;

int main(void) {

    // Dynamiczne przydzielenie pamięci dla tablicy poprzez wskaźnik
    int *tab = new int[N];

    // Użytkownik wprowadza wartości do tablicy
    for (int i = 0; i < N; i++) {
        cout << "Wprowadź wartość dla elementu o indeksie [" << i << "]: ";
        cin >> tab[i];
    }

    // Wyświetlanie zawartości tablicy
    for (int i = 0; i < N; i++) {
        cout << "Element o indeksie [" << i << "] = " << tab[i] << endl;
    }

    // Zwolnienie pamięci zarezerwowanej dla tablicy
    delete[] tab;

    return 0;
}
