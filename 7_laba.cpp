#include <iostream>
#include <string>

using namespace std;

class science{
    public:
    string name;
    virtual void print(){
        cout << "наука - это что на умном" << endl;
    }
};

class mathematica:public science{
    public:
    void print(){
        cout << "математика - наука о числах" << endl;
    }
};

class biology:public science{
    public:
    void print(){
        cout << "биология - наука о всем, что двигается и бегает" << endl;
    }
};

class geometry:public mathematica{
    public:
    void print(){
        cout << "геометрия - предметная область о фигурах" << endl;
    }
};

int main(){

    return 0;
}