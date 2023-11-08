#include <iostream>

#define N 5

using namespace std;

int arr_sum(int (&tab)[N]) {

    int suma = 0;

    for (int i = 0; i < N; ++i) {
        suma = suma + tab[i];
    }

    return suma;
}

int main(void) {

    int tab[N] = {2, 12, 203, -23, 15};

    cout << arr_sum(tab);

    return 0;
}
