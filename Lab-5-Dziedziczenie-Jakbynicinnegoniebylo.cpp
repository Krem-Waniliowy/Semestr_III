#include <iostream>

using namespace std;

class Drukarnia{
    public:
        // Zmienne klasy 'Drukarnia'
        static int ilosc_drukarni;
        string nazwa, adres, godzina_otwarcia, godzina_zamkniecia;

        // Konstruktor domyślny klasy 'Drukarnia'
        Drukarnia(){
            // Zwiększamy zmienną odpowiedzalną za liczenie ilości drukarni za każdym razem gdy utworzymy nową
            ilosc_drukarni++;
        }

        // Konstruktor parametryczny klasy 'Drukarnia'
        Drukarnia(const string nazwa, const string adres, const string godzina_otwarcia, const string godzina_zamkniecia)
                : nazwa (nazwa), adres (adres), godzina_otwarcia (godzina_otwarcia), godzina_zamkniecia (godzina_zamkniecia) {
            ilosc_drukarni++;
        }

        // Destruktor klasy 'Drukarnia'
        ~Drukarnia(){
            ilosc_drukarni--;
        }

        // Metoda wypisz klasy 'Drukarnia'
        void wypisz(){
            cout << "Drukarnia " << nazwa << " pracuje od godziny "
                 << godzina_otwarcia << " do godziny " << godzina_zamkniecia << " pod adresem "
                 << adres << endl;
        }
};

// Zmienna statyczna w zakresie klasy 'Drukarnia'
int Drukarnia::ilosc_drukarni = 0;

// Podklasa klasy 'Drukarnia'
class Stanowisko : public Drukarnia{
    public:
        // Zmienne klasy 'Stanowisko'
        int ilosc_stanowisk = 0;
        int ilosc_pracownikow = 2;
        string nazwa0, adres0, godzina_otwarcia0, godzina_zamkniecia0;
        Drukarnia *wsk1 = nullptr;

        // Konstruktor domyślny klasy 'Stanowisko'
        Stanowisko() = default;

        // Konstruktor parametryczny klasy 'Stanowisko'
        Stanowisko(const string nazwa, const string adres, const string godziny_otwarcia, const string godziny_zamkniecia)
                : Drukarnia(nazwa, adres, godziny_otwarcia, godziny_zamkniecia) {}

        // Metoda 'dodaj' klasy 'Stanowisko'
        void dodaj(){
            if (ilosc_stanowisk + 1 > ilosc_pracownikow){
                cout << "Brakuje pracownikow by obsadzic kolejne stanowisko\n";
            }
            else{
                cout << "Podaj nazwe: ";
                cin >> nazwa0;
                cout << "Adres: ";
                cin >> adres0;
                cout << "Godziny otwarcia: ";
                cin >> godzina_otwarcia0;
                cout << "Godziny zamkniecia: ";
                cin >> godzina_zamkniecia0;
                Drukarnia nowa(nazwa0, adres0, godzina_otwarcia0, godzina_zamkniecia0);

                Drukarnia* nowa_baza = new Drukarnia[ilosc_stanowisk + 1];

                // kopiowanie do nowej tablicy
                for (int i = 0; i < ilosc_stanowisk; i++) {
                    nowa_baza[i] = wsk1[i];
                }

                // Dodanie nowego stanowiska
                nowa_baza[ilosc_stanowisk] = nowa;
                ilosc_stanowisk++;

                // Zwolnienie starej tablicy i przypisanie nowej
                delete[] wsk1;
                wsk1 = nowa_baza;

                cout << "Dodano nowa drukarnie do bazy." << endl;
            }
        }

        void usun(int x){
            if(ilosc_stanowisk <= 1)
            {
                usun_wszystko();
            }
            else {
                Drukarnia *nowa_baza = new Drukarnia[ilosc_stanowisk - 1];
                int y = 0;
                for (int i = 0; i < ilosc_stanowisk; i++) {
                    if (i == x) {

                    } else {
                        nowa_baza[y] = wsk1[i];
                        y++;
                    }
                }

                // Zwolnienie starej tablicy i przypisanie nowej
                delete[] wsk1;
                wsk1 = nowa_baza;
                ilosc_stanowisk--;
            }
        }
        void wypiszDrukarnie(){
            wypisz();
            for(int i = 0; i<ilosc_stanowisk; i++){
                cout << "Nazwa: " << (wsk1+i)->nazwa
                     << "\n" << "Adres: " << (wsk1+i)->adres << "\n"
                     << "Godzina otwarcia: " << (wsk1+i)->godzina_otwarcia << "\n" << "Godzina zamkniecia: "
                     <<(wsk1+i)->godzina_zamkniecia<< endl;

            }
        }
        void usun_wszystko(){
            delete[] wsk1;
        }
};

int main(void){
    Stanowisko *Stanowisko_A = new Stanowisko("Gabinet 1", "tutaj 12", "12:40", "13:00"),
            *Stanowisko_B,
            *Stanowisko_C = new Stanowisko("Nowy", "Tam 12", "11:12", "21:11");

    for(int i = 0; i < 2; i++)
        Stanowisko_A->dodaj();
    Stanowisko_A->wypiszDrukarnie();
    Stanowisko_A->dodaj();
    Stanowisko_A->usun(0);
    cout << "Usunieto przychodnie! \n";
    Stanowisko_A->wypiszDrukarnie();
    Stanowisko_A->dodaj();
    cout << endl << endl << Drukarnia::ilosc_drukarni<<endl << endl;
    Stanowisko_A->wypiszDrukarnie();
    Stanowisko_A->usun_wszystko();
    delete Stanowisko_A;
    cout << Drukarnia::ilosc_drukarni << endl;
    Stanowisko_B= new Stanowisko("Drukowanie", "12 maja", "00:00", "01:00");
    Stanowisko_B->dodaj();
    Stanowisko_C->wypisz();
    delete Stanowisko_B;
    delete Stanowisko_C;
    cout << "usunieto wszystko";


    return 0;
}
