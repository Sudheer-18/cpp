#include<iostream>
using namespace std;

class Salary {
public:
    int salary;
    void get_salary() {  //single inheritance
        cin >> salary;
    }
};

class Programmer : public Salary {
public:
    string name;
    void get_name() {
        cin >> name;
    }
};

int main() {
    Programmer p1;
    cout << "Enter the salary: " << endl;
    p1.get_salary();
    cout << "Enter the Programmer name: " << endl;
    p1.get_name(); 
    cout << "Programmer: " << p1.name << endl;
    cout << "Salary: " << p1.salary << endl;

    return 0;
}

