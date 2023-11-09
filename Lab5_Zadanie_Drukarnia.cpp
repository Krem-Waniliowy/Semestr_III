#include <iostream>
#include <string>

using namespace std;

// pkt 1 - Zdefiniowanie klasy do tematu
class Drukarnia {
// pkt 2 - utworzenie prywatniego pola ze zmiennymi
private:
    string* pola;
    int liczbaPol;

public:
    // pkt 3 - Konstruktor
    Drukarnia() : pola(nullptr), liczbaPol(0) {}

    // pkt 4 - Dekonstruktor
    ~Drukarnia() {
        delete[] pola;
    }

    // pkt 5 - Metoda dodaj()
    void dodaj(const string& pole) {
        string* nowaTablica = new string[liczbaPol + 1];

        for (int i = 0; i < liczbaPol; i++) {
            nowaTablica[i] = pola[i];
        }

        nowaTablica[liczbaPol] = pole;

        delete[] pola;

        pola = nowaTablica;
        liczbaPol++;
    }

    // pkt 6 - Metoda czyPoleIstnieje()
    bool czyPoleIstnieje(const string& pole) {
        for (int i = 0; i < liczbaPol; i++) {
            if (pola[i] == pole) {
                return true;
            }
        }
        return false;
    }

    // pkt 7 - Metoda zamienPole
    void zamienPole(string& pole1, string& pole2) {
        int indeks1 = -1;
        int indeks2 = -1;

        // Znajdź indeksy pól pole1 i pole2
        for (int i = 0; i < liczbaPol; i++) {
            if (pola[i] == pole1) {
                indeks1 = i;
            }
            if (pola[i] == pole2) {
                indeks2 = i;
            }
        }

        // Jeśli znaleziono oba pola, zamień je
        if (indeks1 != -1 && indeks2 != -1) {
            string temp = pola[indeks1];
            pola[indeks1] = pola[indeks2];
            pola[indeks2] = temp;
        }
    }


    public:
        // Getter dla liczbyPol
        int getLiczbaPol() {
            return liczbaPol;
        }

        // Getter dla pola (indeksu i)
        string getPole(int i) {
            if (i >= 0 && i < liczbaPol) {
                return pola[i];
            }
            return "";
        }
};

int main() {
    // pkt 8 - Obiekt klasy Drukarnia
    Drukarnia drukarnia;

    // Dodawanie pol - ad pkt 8
    drukarnia.dodaj("Zamowienie 1");
    drukarnia.dodaj("Zamowienie 2");
    drukarnia.dodaj("Zamowienie 3");

    // Sprawdzanie istnienia - ad pkt 8
    cout << "Czy pole2 istnieje: " << (drukarnia.czyPoleIstnieje("Zamowienie 2") ? "Tak" : "Nie") << endl;

    // pkt 9
    string pole1 = "Zamowienie 1";
    string pole3 = "Zamowienie 3";
    drukarnia.zamienPole(pole1, pole3);

    cout << "Kolekcja pól po zamianie: ";
    for (int i = 0; i < drukarnia.getLiczbaPol(); i++) {
        cout << drukarnia.getPole(i) << " ";
    }
    cout << endl;

    return 0;
}
