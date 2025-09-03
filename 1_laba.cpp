#include <iostream>
#include <string>
using namespace std;
//имя - string, факультет - string, курс - int
class Student{
public:
    string name ;
    string facultet;
    int course;

    void print(){
        cout << name << " " << facultet << " " << course << endl;
    }
};

int main(){
    Student student;
    student.name = "Роман";
    student.facultet = "informatika";
    student.course = 12;
    student.print();

    return 0;
}