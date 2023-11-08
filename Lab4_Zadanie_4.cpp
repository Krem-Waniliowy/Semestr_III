#include <iostream>
#include <string>

using namespace std;

class person {

    public:
        string f_name;
        string l_name;
        int age;

};

int main(void) {

    // Tworzenie wskaźnika do klasy person, osoba1
    person *osoba1 = new person;

    // Przypisanie danych
    osoba1->f_name = "First";
    osoba1->l_name = "Last";
    osoba1->age = 18;

    // Wyświetlenie danych
    cout << "Name: " << osoba1->f_name << endl;
    cout << "Last name: " << osoba1->l_name << endl;
    cout << "Age: " << osoba1->age << endl;

    return 0;
}
