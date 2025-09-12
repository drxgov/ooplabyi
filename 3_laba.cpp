#include <iostream>
#include <cmath>

using namespace std;

class parallelogram {
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
    parallelogram(double x = 1, double y = 1, double z = 1) {
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
        else if (temp == 2){
            double ns;
            ns = sStorona + sStorona * xChange / 100;
            if (checkValue(ns)){
                sStorona = ns;
            }
        }
        // else if (temp == 3) setAngle(angle + angle * xChange / 100);
        else if (temp == 3){
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
    double perimetr() const { return 2 * (fStorona + sStorona);}
    double square() const {return fStorona * sStorona * sin(degToRad(angle ));}
    double height() const {return sStorona*sin(degToRad(angle));}
    double diag1() const {return sqrt(fStorona * fStorona + sStorona * sStorona - 2 * fStorona * sStorona * cos(degToRad(angle )));}
    double diag2() const {return sqrt(fStorona * fStorona + sStorona * sStorona + 2 * fStorona * sStorona * cos(degToRad(angle )));}
};

int main() {
    cout << "=== Тест 1: корректный объект ===" << endl;
    parallelogram p1(3, 4, 60);
    p1.print();
    cout << "Периметр: " << p1.perimetr() << endl;
    cout << "Площадь: " << p1.square() << endl;
    cout << "Высота: " << p1.height() << endl;
    cout << "Диагональ 1: " << p1.diag1() << endl;
    cout << "Диагональ 2: " << p1.diag2() << endl;
    cout << endl;

    cout << "=== Тест 2: некорректные параметры (отрицательные и угол вне диапазона) ===" << endl;
    parallelogram p2(-5, 0, 200); // автоматически исправится на 1,1,60
    p2.print();
    cout << "isValid(): " << (p2.isValid() ? "OK" : "Ошибка") << endl;
    cout << endl;

    cout << "=== Тест 3: изменение параметров (change) ===" << endl;
    parallelogram p3(5, 7, 120);
    p3.print();
    // вручную проверим все 3 варианта:
    cout << "Увеличим боковую сторону на 20%" << endl;
    // эмулируем ввод (лучше в реальной программе — через cin, тут просто пример логики)
    // допустим change() вызовет внутренние изменения
    // Для теста проще вручную вызвать изменение:
    p3.change(); // попробуй сам ввести 1 и 20 при выполнении
    p3.print();
    cout << endl;

    cout << "=== Тест 4: const объект ===" << endl;
    const parallelogram p4(6, 8, 45);
    p4.print();
    cout << "Периметр (const): " << p4.perimetr() << endl;
    cout << "Площадь (const): " << p4.square() << endl;
    cout << "Высота (const): " << p4.height() << endl;
    cout << "Диагональ 1 (const): " << p4.diag1() << endl;
    cout << "Диагональ 2 (const): " << p4.diag2() << endl;
    // p4.change(); // ❌ Ошибка компиляции: change() не const
    cout << endl;

    cout << "=== Все тесты завершены ===" << endl;

    return 0;
}