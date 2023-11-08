#include <iostream>
#include <string>
#include <utility>

using namespace std;

void swap(int& a, int& b) {

    int c;

    c = a;
    a = b;
    b = c;
}

int main(void) {

    int a = 3;
    int b = 6;

    cout << a << " " << b << endl;

    swap(a, b);

    cout << a << " " << b << endl;

    return 0;
}
