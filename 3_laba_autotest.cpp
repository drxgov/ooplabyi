#include <cassert>
#include <cmath>
#include "3_laba.cpp"  // подключи сюда свой файл с классом

int main() {
    // Тест 1: корректный параллелограмм
    Parallelogram p1(3, 4, 90);
    assert(p1.isValid());
    assert(fabs(p1.perimetr() - 14) < 1e-9);
    assert(fabs(p1.square() - 12) < 1e-9);
    assert(fabs(p1.height() - 4) < 1e-9);
    assert(fabs(p1.diag1() - 5) < 1e-9); // прямоугольный треугольник (3,4,5)
    assert(fabs(p1.diag2() - 5) < 1e-9); // то же самое

    // Тест 2: угол 60 градусов, равные стороны (ромб)
    Parallelogram p2(2, 2, 60);
    assert(p2.isValid());
    assert(fabs(p2.perimetr() - 8) < 1e-9);
    assert(fabs(p2.square() - (2 * 2 * sin(M_PI/3))) < 1e-9);
    assert(fabs(p2.height() - (2 * sin(M_PI/3))) < 1e-9);

    // Тест 3: некорректные стороны (отрицательные)
    Parallelogram p3(-5, -10, 45);
    assert(p3.isValid()); // конструктор подставит 1
    assert(fabs(p3.perimetr() - 4) < 1e-9); // (1+1)*2

    // Тест 4: некорректный угол
    Parallelogram p4(5, 5, 200); // угол заменится на 1
    assert(p4.isValid());
    assert(p4.square() > 0);

    // Тест 5: квадрат (угол 90, стороны равные)
    Parallelogram p5(10, 10, 90);
    assert(fabs(p5.square() - 100) < 1e-9);
    assert(fabs(p5.perimetr() - 40) < 1e-9);
    assert(fabs(p5.height() - 10) < 1e-9);

    return 0;
}
