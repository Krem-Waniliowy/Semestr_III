#include <iostream>

using namespace std;

class Zamowienia {
public:
    static int ilosc_zamowien; // zmienna statyczna do zliczania obiektów

    string nazwa_zamowienia;
    string imie_klienta;
    string adres_klienta;
    string info_druku;
    int naklad;

    // konstruktor parametryczny;
    Zamowienia(const string& order, const string& name, const string& address, const string& details, int qty)
        : nazwa_zamowienia(order), imie_klienta(name), adres_klienta(address), info_druku(details), naklad(qty) {
        ilosc_zamowien++;
    }

    // destruktor
    ~Zamowienia() {
        ilosc_zamowien--;
    }

    // metoda wypisz()
    void wypisz() const {
        cout << "Nazwa zamowienia: " << nazwa_zamowienia << endl;
        cout << "Imie klienta: " << imie_klienta << endl;
        cout << "Adreas klienta: " << adres_klienta << endl;
        cout << "Informacje o zamowieniu: " << info_druku << endl;
        cout << "Naklad: " << naklad << endl;
        cout << endl;
    }

    static void usunZamowienie() {
        ilosc_zamowien--;
    }
};

class Magazyn : public Zamowienia {

public:
    // zmienne
    const int limit;
    int ilosc_obiektow;
    Zamowienia** pozycje;

    // konstruktor parametryczny
    Magazyn(const string& order, const string& name, const string& address, const string& details, int qty, int storageLimit)
        : Zamowienia(order, name, address, details, qty), limit(storageLimit), ilosc_obiektow(0) {
        pozycje = new Zamowienia*[limit];
    }

    // destruktor
    ~Magazyn() {
        for (int i = 0; i < ilosc_obiektow; ++i) {
            delete pozycje[i];
        }
        delete[] pozycje;
    }

    // metoda wypisz
    void wypiszDostepneObiekty() {
        for (int i = 0; i < ilosc_obiektow; ++i) {
            cout << "\nPozycja nr." << (i + 1) << endl;
            pozycje[i]->wypisz();
        }
    }

    // metoda dodaj
    void dodajObiekt(Zamowienia* nowaPozycja) {
        if (ilosc_obiektow < limit) {
            pozycje[ilosc_obiektow] = nowaPozycja;
            ilosc_obiektow++;
        }
        else {
            cout << "Magazyn osiagnal limit!" << endl;
        }
    }

    // metoda usun
    void usunObiekt(int indeks) {
        if (indeks >= 0 && indeks < ilosc_obiektow) {
            delete pozycje[indeks];
            for (int i = indeks; i < ilosc_obiektow - 1; ++i) {
                pozycje[i] = pozycje[i + 1];
            }
            ilosc_obiektow--;
        } else {
            cout << "Nieprawidlowy indeks obiektu do usuniecia!" << endl;
        }
    }
};

int Zamowienia::ilosc_zamowien = 0;

int main(void) {
    // stworzenie domyślnego magazynu Magazyn_A
    Magazyn Magazyn_A("Zamowienie_A", "Klient_A", "Adres_A", "Info_A", 100, 5);

    // dodanie co najmniej jednego obiektu do Magazyn_A
    Magazyn_A.dodajObiekt(new Zamowienia("Zamowienie_A1", "Klient_A1", "Adres_A1", "Info_A1", 200));

    // stworzenie obiektów Magazyn_B i Magazyn_C zgodnie z opisem
    Magazyn Magazyn_B("Zamowienie_B", "Klient_B", "Adres_B", "Info_B", 150, 5);
    Magazyn Magazyn_C("Zamowienie_C", "Klient_C", "Adres_C", "Info_C", 120, 5);

    Magazyn_B.dodajObiekt(new Zamowienia("Zamowienie_B1", "Klient_B1", "Adres_B1", "Info_B1", 70));
    Magazyn_B.dodajObiekt(new Zamowienia("Zamowienie_B2", "Klient_B2", "Adres_B2", "Info_B2", 56));
    Magazyn_C.dodajObiekt(new Zamowienia("Zamowienie_C1", "Klient_C1", "Adres_C1", "Info_C1", 123));
    Magazyn_C.dodajObiekt(new Zamowienia("Zamowienie_C2", "Klient_C2", "Adres_C2", "Info_C2", 240));

    // usunięcie jednego obiektu z Magazyn_B
    Magazyn_B.usunObiekt(0);

    // wypisanie dostępnych obiektów w każdym z magazynów
    cout << "Obiekty w Magazynie_A:" << endl;
    Magazyn_A.wypiszDostepneObiekty();

    cout << "Obiekty w Magazynie_B:" << endl;
    Magazyn_B.wypiszDostepneObiekty();

    cout << "Obiekty w Magazynie_C:" << endl;
    Magazyn_C.wypiszDostepneObiekty();

    // usuniecie reszty obiektow i sprawdzenie ilosci
    for (int i = 0; i < Magazyn_A.ilosc_obiektow; ++i) {
        Magazyn_A.usunObiekt(0);
    }

    for (int i = 0; i < Magazyn_B.ilosc_obiektow; ++i) {
        Magazyn_B.usunObiekt(0);
    }

    for (int i = 0; i < Magazyn_C.ilosc_obiektow; ++i) {
        Magazyn_C.usunObiekt(0);
    }

    cout << "Ilosc obiektow w Magazynie_A: " << Magazyn_A.ilosc_obiektow << endl;
    cout << "Ilosc obiektow w Magazynie_B: " << Magazyn_B.ilosc_obiektow << endl;
    cout << "Ilosc obiektow w Magazynie_C: " << Magazyn_C.ilosc_obiektow << endl;

    return 0;
}
