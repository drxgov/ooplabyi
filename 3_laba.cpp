#include <iostream>
#include <cmath>
using namespace std;

class parallelogram{
    public:
    double fStorona;
    double sStorona;
    double angle;
    void change(int xVolume, int xAngle){
        cout << endl << "1 - боковая сторона" << endl << "2 - основная сторона" << endl << "3 - угол" << endl << "выберите сторону:";
        int temp;
        cin >> temp;
        int xChange;
        cout << "введите на сколько процентов увеличить/уменьшить: ";
        cin >> xChange;
        if (temp == 1) fStorona = fStorona+fStorona*xChange/100;
        if (temp == 2) sStorona = sStorona+sStorona*xChange/100;
        if (temp == 3) angle = angle+angle*xChange/100;
    }
    void print(){
        cout << fStorona << " " << sStorona << " " << angle << endl;
    }
    void findPerimetrAndSquare(){
        double per;
        per = fStorona*2 + sStorona*2;
        double sqa;
        sqa = fStorona*sStorona*sin(angle);
        cout << "площадь параллелограмма: " << sqa << endl << "периметр паралеллограмма: " << per << endl;
    }
    void findDiagonales(){
        double d1 = sqrt(fStorona*fStorona + sStorona*sStorona - 2*fStorona*sStorona*cos(angle));
        double d2 = sqrt(fStorona*fStorona + sStorona*sStorona + 2*fStorona*sStorona*cos(angle));
        cout << "первая диагональ: " << d1 << endl << "вторая диагональ: " << d2 << endl;
    }
    void findVisota(){
        double h;
        h = fStorona*sin(angle);
        cout << "высота параллелограмма: " << h << endl;
    }
};
int main(){
    parallelogram test;
    test.fStorona = 100;
    test.sStorona = 200;
    test.angle = 20;
    test.print();
    test.change(1,123);
    test.print();
    test.findPerimetrAndSquare();
    test.findDiagonales();
    test.findVisota();
    return 0;
}