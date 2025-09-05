#include <iostream>
#include <vector>

using namespace std;

class figure{
    public:
    virtual int printCountCorners()  = 0;
    virtual ~figure(){}
};

class parallelepiped:public figure{
    public:
    int printCountCorners(){
        return 8;
    }
};

class pyramid:public figure{
    public:
    int printCountCorners(){
        return 4;
    }
};

class tetrahedron:public figure{
    public:
    int printCountCorners(){
        return 4;
    }
};

class triangle:public figure{
    public:
    int printCountCorners(){
        return 3;
    }
};

int main(){

    vector<figure*> figures;
    figures.push_back(new parallelepiped());
    figures.push_back(new pyramid());
    figures.push_back(new tetrahedron());
    figures.push_back(new triangle());

    for(auto x:figures){
        cout << "количество углов: " << x -> printCountCorners() << endl;
    }
    return 0;
}