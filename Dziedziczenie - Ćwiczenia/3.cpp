#include <iostream>
#include <string>

using namespace std;

class Marks {
public:
    static int globalRollNumber;
    int roll_number;
    string name;
    double mark;

    Marks() {
        cout << "Insert student's name: ";
        cin >> name;
        cout << "Insert student's mark: ";
        cin >> mark;
        roll_number = ++globalRollNumber;
    }

    static void resetGlobalRollNumber() {
        globalRollNumber = 0;
    }
};

int Marks::globalRollNumber = 0;

class Physics : public Marks {
public:
    Physics() = default;
};

class Chemistry : public Marks {
public:
    Chemistry() = default;
};

class Mathematics : public Marks {
public:
    Mathematics() = default;
};

int main() {
    int s_num = 0;

    cout << "Enter number of students: ";
    cin >> s_num;

    cout << "\nPhysics\n";
    Physics* tab_p = new Physics[s_num];
    Physics::resetGlobalRollNumber();

    cout << "\nChemistry\n";
    Chemistry* tab_c = new Chemistry[s_num];
    Chemistry::resetGlobalRollNumber();

    cout << "\nMathematics\n";
    Mathematics* tab_m = new Mathematics[s_num];
    Mathematics::resetGlobalRollNumber();

    for (int i = 0; i < s_num; ++i) {
        cout << "\nStudent " << i + 1 << " details:\n";
        cout << "Name: " << tab_p[i].name << endl;
        cout << "Roll Number: " << tab_p[i].roll_number << endl;
        cout << "Average Marks: " << (tab_p[i].mark + tab_c[i].mark + tab_m[i].mark) / 3.0 << endl;
    }

    delete[] tab_p;
    delete[] tab_c;
    delete[] tab_m;

    return 0;
}
