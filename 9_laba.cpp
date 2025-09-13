#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

double f(double x) {
    if (x == 1.0) throw runtime_error("Деление на ноль: x = 1");
    if ((x + 1) / (x - 1) <= 0) throw runtime_error("Логарифм от неположительного числа: x + 1 <= 0");
    return log((x + 1) / (x - 1));
}

int main() {
    try {
        double xStart = -2.0, xEnd = 8.0, dx = 0.5;
        vector<double> a, b, c;        
        for (double x = xStart; x <= xEnd + 1e-9; x += dx) {
            try {
                double val = f(x);
                a.push_back(val);
                b.push_back(val ); 
                cout << "x = " << x << "  f(x) = " << val << endl;
            } catch (const exception& e) {
                cerr << "Ошибка при x=" << x << ": " << e.what() << endl;
                a.push_back(NAN);
                b.push_back(NAN);
            }
        }
        cout << endl;
        for (size_t i = 0; i + 1 < a.size(); i++) {
            try {
                if (isnan(a[i+1]) || isnan(b[i+1])) throw runtime_error("Некорректные значения в массивах a или b");
                double underRoot = a[i+1] * b[i+1];
                if (underRoot < 0) throw runtime_error("Отрицательное подкоренное выражение");
                c.push_back(sqrt(underRoot));
                cout << "c[" << i << "] = " << c.back() << endl;
            } 
            catch (const exception& e) {
                cerr << "Ошибка при вычислении c[" << i << "]: " << e.what() << endl;
                c.push_back(NAN);
            }
        }

    } catch (const exception& e) {
        cerr << "Критическая ошибка: " << e.what() << endl;
    }

    return 0;
}
