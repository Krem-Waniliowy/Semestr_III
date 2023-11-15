#include <iostream>

class Fruit {
public:
    int f_num;
    
    Fruit(int f_num) : f_num(f_num) {}
};

class Apples : public Fruit {
public:
    int apples_num;

    // Parametrized constructor
    Apples(int f_num) : Fruit(f_num) {
        apples_num = f_num / 2;
    }
};

class Mangoes : public Fruit {
public:
    int mangoes_num;
    
    Mangoes(int fNum) : Fruit(fNum) {
        mangoes_num = fNum / 2;
    }
};

int main() {
    Fruit basket(20);
    Apples apples(basket.f_num);
    Mangoes mangoes(basket.f_num);

    std::cout << "Fruit total in a basket: " << basket.f_num << std::endl;
    std::cout << "Apples in a basket: " << apples.apples_num << std::endl;
    std::cout << "Mangoes in a basket: " << mangoes.mangoes_num << std::endl;

    return 0;
}
