/*Создать класс машина, содержащий в качестве параметров марку (строка), число цилиндров, мощность. 
Определить конструкторы, деструктор и функцию печати. Создать public-производный класс грузовик, имеющий 
дoполнительный вещественный параметр - грузоподъемность кузова.
Определить конструкторы по умолчанию и с разным числом параметров, деструктор, функцию печати. 
Определить функции переназначения марки и грузоподъемности.*/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class car{
    public:
    string brand;
    int countOfСylinders;
    int power;
    car(string x, int y, int z) : brand(x), countOfСylinders(y),power(z){}
    ~car(){};
    void print() {
        printf("%s %d %d",brand,countOfСylinders,power);
    }
};

class track:public car{
    public:
    float 
}

int main(){

    return 0;
}