#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

class parabola{
    public:
    double a,b,c;
    parabola(double x = 0,double y = 0, double z = 0) : a(x),b(y),c(z) {}
    ~parabola(){}
    
    void printParabola(){
        cout << "y = " << a << "x^2 ";
        if (b >= 0) cout << "+ " << b << "x ";
        else cout << "- " << -b << "x ";
        if (c >= 0) cout << "+ " << c;
        else cout << "- " << -c;
        cout << endl;
    }
    void extremumParabola(){
        if (a == 0) {
        cout << "Это не парабола" << endl;
        return;
        }
        double x0 = -b / (2 * a);
        double y0 = a * x0 * x0 + b * x0 + c;
        cout << "Экстремум в точке (" << x0 << ", " << y0 << ")";
        if (a > 0) cout << " -> минимум" << endl;
        else cout << " -> максимум" << endl;
    }
    bool operator==(const parabola &other) const {
        return (a == other.a && b == other.b && c == other.c);
    }
    vector<double> operator/(const parabola &other){
        vector<double> res;
        double A = a-other.a;
        double B = b - other.b;
        double C = c - other.c;

        if(A == 0 && B == 0 && C == 0) {
            return res;
        }
        double d = B*B - 4*A*C;
        if (A == 0) { 
        if (B != 0) {
            res.push_back(-C / B);
        }
        return res;
    }
        if (d < 0){
            cout << "точек пересечения нету" << endl;
            return res;
        }
        else if (d == 0){
            res.push_back(-B/(2*A));
        }
        else{
            res.push_back((-B+sqrt(d))/(2*A));
            res.push_back((-B-sqrt(d))/(2*A));
        }
        return res;
    }
};

int main() {
    cout << "=== Автотесты ===" << endl;

    // Тест 1: сравнение одинаковых парабол
    parabola p1(1, -2, 1);
    parabola p2(1, -2, 1);
    assert(p1 == p2);
    cout << "Тест 1 пройден ✅" << endl;

    // Тест 2: сравнение разных парабол
    parabola p3(1, 0, -1);
    assert(!(p1 == p3));
    cout << "Тест 2 пройден ✅" << endl;

    // Тест 3: пересечение в одной точке
    auto pts1 = p1 / p3; // x^2 - 2x + 1  и  x^2 - 1
    assert(pts1.size() == 1);
    assert(fabs(pts1[0] - 1.0) < 1e-9);
    cout << "Тест 3 пройден ✅" << endl;

    // Тест 4: совпадающие параболы
    auto pts2 = p1 / p2;
    assert(pts2.empty());
    cout << "Тест 4 пройден ✅" << endl;

    // Тест 5: две точки пересеченияв что то здесь еще есть
    parabola p4(1, 0, 0);   // y = x^2
    parabola p5(-1, 0, 0);  // y = -x^2
    auto pts3 = p4 / p5;    // 2x^2 = 0 => x=0, только одна точка!
    assert(pts3.size() == 1 && fabs(pts3[0]) < 1e-9);
    cout << "Тест 5 пройден ✅" << endl;

    // Тест 6: нет пересечений
    parabola p6(1, 0, 1);  // y = x^2 
    parabola p7(1, 0, 5);  // y = x^2 + 5
    auto pts4 = p6 / p7;
    assert(pts4.empty());
    cout << "Тест 6 пройден ✅" << endl;

    cout << "=== Все тесты успешно пройдены ✅ ===" << endl;
    return 0;
}