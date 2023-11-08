#include <iostream>
#include <string>

#define N 10

using namespace std;

int add(int a, int b) {

    return a + b;
}

int substract(int a, int b) {

    return a - b;
}

int multiply(int a, int b) {

    return a * b;
}

int divide(int a, int b) {

    if (b == 0) {
        cout << "Blad - dzielenie przez zero.\n";
        exit(1);
    }
    return a / b;
}

int main(void) {

    // Zmienne
    int a, b;
    char op = '0';
    // Wskaźnik do funkcji
    int (*fPtr)(int, int);

    // Wprowadzanie wartości
    cout << "Podaj wartosc a: ";
    cin >> a;
    cout << "Podaj wartosc b: ";
    cin >> b;

    // Wybór operacji
    cout << "Podaj operacje do przeprowadzenia (+, -, *, /): ";
    cin >> op;

    // Przypisanie funkcji do wskaźnika na nią poprzez 'switch'
    switch (op) {
        case '+':
            fPtr = add;
            break;
        case '-':
            fPtr = substract;
            break;
        case '*':
            fPtr = multiply;
            break;
        case '/':
            fPtr = divide;
            break;
    }

    // Wynik
    cout << "Wynik operacji: " << fPtr(a, b) << endl;

    return 0;
}
