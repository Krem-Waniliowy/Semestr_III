#include <iostream>
#include <string>

#define N 5

using namespace std;

class Item {
    public:
        string name;
        double price;
        bool availability;

    public:
    // constructor
    Item() {
        name = "Coca-Cola";
        price = 5.99;
        availability = true;
    }
};

// availability check
void ava(bool& x) {
    if (x == true) cout << "Item is available.\n";
    else cout << "Item is not available.\n";
}

// price change
void pri(Item& item) {
    cout << "Insert new price for " << item.name;
    cin >> item.price;
    cout << "New price for this item is: " << item.price << endl;
}

int main(void) {

    Item i1;

    // wykonywanie metod
    ava(i1.availability);
    pri(i1);

    return 0;
}
