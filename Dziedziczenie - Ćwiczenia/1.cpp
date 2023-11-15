#include <iostream>

using namespace std;

class Mammals {

public:
    void say_M() {
        cout << "I am mammal!" << endl;
    }
};

class MarineAnimals {

public:
    void say_MA() {
        cout << "I am a marine animal!" << endl;
    }
};

class BlueWhale : public Mammals, public MarineAnimals {

public:
    void say_both() {
        cout << "I am both: mammal and a marine animal!" << endl;
    }
};

int main(void) {

    Mammals o1;
    MarineAnimals o2;
    BlueWhale o3;

    o1.say_M();
    o2.say_MA();
    o3.say_M();
    o3.say_MA();
    o3.say_both();
    return 0;
}