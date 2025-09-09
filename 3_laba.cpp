#include <iostream>
#include <cmath>

using namespace std;

class Parallelogram {
private:
    double fStorona; 
    double sStorona; 
    double angle;    

    double degToRad(double deg) const {
        return deg * M_PI / 180.0;
    }
    bool checkValue(double value){
        if (value <= 0) {
            cout << "число должно быть положительным" << endl;
            return false;
        }
        else return true;
    }

    bool checkAngle(double angle){
        if (angle <= 0 || angle >= 180){
            cout << "угол должен быть от 0 до 180" << endl;
            return false;
        }
        else return true;
    }

public:
    Parallelogram(double x = 1, double y = 1, double z = 1) {
        if (checkValue(x)) fStorona = x;
        else fStorona = 1;
        if (checkValue(y)) sStorona = y;
        else sStorona = 1;
        if (checkAngle(z)) angle = z;
        else angle = 1;
    }
    bool isValid() const {
        return (fStorona > 0 && sStorona > 0 && angle > 0 && angle < 180);
    }
    void change() {
        cout << endl << "1 - боковая сторона" 
             << endl << "2 - основная сторона" 
             << endl << "3 - угол" 
             << endl << "Выберите свойство: ";
        int temp;
        cin >> temp;
        int xChange;
        cout << "Введите на сколько процентов увеличить/уменьшить: ";
        cin >> xChange;
        // if (temp == 1) setStorona(fStorona + fStorona * xChange / 100);
        if (temp == 1){
            double ns;
            ns = fStorona + fStorona * xChange / 100;
            if (checkValue(ns)){
                fStorona = ns;
            }
        }
        // else if (temp == 2) setStorona(sStorona + sStorona * xChange / 100);
        if (temp == 2){
            double ns;
            ns = sStorona + sStorona * xChange / 100;
            if (checkValue(ns)){
                sStorona = ns;
            }
        }
        // else if (temp == 3) setAngle(angle + angle * xChange / 100);
        if (temp == 3){
            double ns;
            ns = angle + angle * xChange / 100;
            if (checkAngle(ns)){
                angle = ns;
            }
        }
    }
    void print() const {
        cout << "Боковая: " << fStorona  << " Основная: " << sStorona  << " Угол: " << angle << endl;
    }
    double perimetr(){ return 2 * (fStorona + sStorona);}
    double square(){return fStorona * sStorona * sin(degToRad(angle ));}
    double height(){return sStorona*sin(degToRad(angle));}
    double diag1(){return sqrt(fStorona * fStorona + sStorona * sStorona - 2 * fStorona * sStorona * cos(degToRad(angle )));}
    double diag2(){return sqrt(fStorona * fStorona + sStorona * sStorona + 2 * fStorona * sStorona * cos(degToRad(angle )));}
};
