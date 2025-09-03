#include <iostream>
#include <string>
using namespace std;
//имя - string, факультет - string, курс - int
class Student{
public:
    string name ;
    string facultet;
    int course;
    void print();
    Student(string a, string fac, int b){
        name = a;
        facultet = fac;
        course = b;
    }

    ~Student(){
    }

};

void Student::print(){
    cout << name << " " << facultet << " " << course << endl;
}
int main(){
    Student student("Roman","informatika",12);
    student.print();
    return 0;
}