#include <iostream>

using namespace std;

class B{
    int a;
    public:
    B(int x) : a(x){}
    void show_B(){
        cout << "B = "<< a << endl;
    }
};

class D1: public B{
    int b;
    public:
    D1(int x, int y) : b(x),B(y) {}
    void show_D1(){
        cout << "D1 = " << b << endl;
        show_B();
    }
};

class D2: private B{
    int c;
    public:
    D2(int x, int y): c(x),B(y){}
    void show_D2(){
        cout << "D2 = " << c << endl;
        show_B();
    }
};

class D3: private B{
    int d;
    public:
    D3(int x, int y): d(x),B(y){}
    void show_D3(){
        cout << "D3 = " << d << endl;
        show_B();
    }
};

class D4: private D1{
    int c;
    public:
    D4(int x, int y, int z) : c(x),D1(y,z){}
    void show_D4(){
        cout << "D4 = " << c << endl;
        show_D1();
    }
};

class D5: public D1,public D2, private D3{
    int e;
    public:
    D5(int x, int y, int z,int w, int i) : D1(y, z), D2(y, z), D3(w, i), e(x) {}
    void show_D5(){
        cout << "D5 = " << e << endl;
        show_D1();
        show_D2();
        show_D3();
    }
};

int main(){
    
    return 0;
}