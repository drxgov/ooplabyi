#include <iostream>
#include <string>

using namespace std;

class car{
    public:
    string brand;
    int countOfСylinders;
    int power;
    car(string x = "", int y = 0, int z = 0) : brand(x), countOfСylinders(y),power(z){}
    ~car(){};
    void print() {
        cout << brand << " " << countOfСylinders << " " << power << endl;
        }
};

class track:public car{
    public:
    float bodyLoadСapacity;
    track(string x = "", int y  = 0, int z = 0, float w = 0) : car(x,y,z), bodyLoadСapacity(w){}
    ~track(){};
    void print() {
        cout << brand << " " << countOfСylinders << " " << power << " " << bodyLoadСapacity << endl;
    }
    void changeBrand(string x){
        brand = x;
    }
    void changeBodyLoadСapacity(float x){
        bodyLoadСapacity = x;
    }
};

int main() {
    car c("Toyota", 4, 150);
    cout << "Test 1 - car print: ";
    c.print();  // Ожидаемый вывод: Toyota 4 150
    track t("Volvo", 6, 400, 12.5);
    cout << "Test 2 - track print: ";
    t.print();  // Ожидаемый вывод: Volvo 6 400 12.50
    t.changeBrand("Scania");
    cout << "Test 3 - change brand: ";
    t.print();  // Ожидаемый вывод: Scania 6 400 12.50
    t.changeBodyLoadСapacity(15.75);
    cout << "Test 4 - change body load: ";
    t.print();  // Ожидаемый вывод: Scania 6 400 15.75
    car* cptr = &t;
    cout << "Test 5 - base pointer to track: ";
    cptr->print();  // Тут будет вызван print базового класса, так как функция не virtual

    return 0;
}