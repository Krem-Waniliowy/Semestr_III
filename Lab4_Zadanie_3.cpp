#include <iostream>
#include <string>

#define N 10

using namespace std;

void count(const int* tab, int x, int* end) {

    int count = 0;

    for ( ;tab < end; ++tab) {
        if (*tab == x) {
            count++;
        }
    }

    cout << "Element " << x << " występuje w tablicy " << count << " razy" << endl;
}

int main(void) {
    int tab[N] = {1, 2, 3, 3, 3, 6, 12, 22, 90, 120};

    int x = 3; // Element to count
    int *ptr_end = end(tab);
    count(tab, x, ptr_end);

    return 0;
}
