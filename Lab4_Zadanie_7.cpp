#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int amount;

public:
    Product() {
        id = 0;
        name = "name";
        price = 0;
        amount = 0;
    }

    Product(int a, string b, double c, int d) {
        id = a;
        name = b;
        price = c;
        amount = d;
    }
};

int main(void) {
    Product* list = nullptr;
    int list_size = 0;
    int choice;
    bool check = true;

    do {
        cout << "1 - add item" << endl;
        cout << "2 - delete item" << endl;
        cout << "3 - show list of items in stock" << endl;
        cout << "4 - end program" << endl;
        cout << "Choose action: ";
        cin >> choice;

        switch (choice) {
            case 1: // adding item

                int id;
                string name;
                double price;
                int amount;

                cout << "\nInsert id of the item: ";
                cin >> id;
                cout << "\nInsert name of the item: ";
                cin >> name;
                cout << "\nInsert price of the item: ";
                cin >> price;
                cout << "\nInsert amount of items you add: ";
                cin >> amount;
                cout << "\n";

                // Allocate memory for a new array (increase size by 1)
                Product* new_list = new Product[list_size + 1];

                // Copy the contents of the old list to the new list
                for (int i = 0; i < list_size; i++) {
                    new_list[i] = list[i];
                }

                // Add the new product to the end of the new list
                new_list[list_size] = Product(id, name, price, amount);

                // Free the old list
                delete[] list;

                // Update the list pointer and size
                list = new_list;
                list_size++;

                break;
            case 2: // deleting item
                // You can implement code to delete items here
                break;
            case 3: // showing list of items
                // You can display the list of items here
                break;
            case 4:
                check = false;

                // Free the memory for the list before exiting
                delete[] list;
                break;
        }
    } while (check);

    return 0;
}
