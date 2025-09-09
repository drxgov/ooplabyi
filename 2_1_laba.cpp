#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string facultet;
    int course;

public:
    Student() : name("Unknown"), facultet("Unknown"), course(0) {}
    Student(const string& n, const string& f, int c) : name(n), facultet(f), course(c) {}
    Student(const Student& other) : name(other.name), facultet(other.facultet), course(other.course) {}
    ~Student() {}
    string getName() const { return name; }
    string getFacultet() const { return facultet; }
    int getCourse() const { return course; }
    void setName(const string& n) { name = n; }
    void setFacultet(const string& f) { facultet = f; }
    void setCourse(int c) { course = c; }
    void displayInfo() const {
        cout << "Имя: " << name << ", Факультет: " << facultet << ", Курс: " << course << endl;
    }
};

typedef void (Student::*studentMethod)() const;

int main() {
    Student st1;
    Student st2("Roman", "Informatika", 2); 
    Student st3 = st2;                     
    Student* pSt = new Student("Ivan", "Math", 3);
    pSt->displayInfo();
    delete pSt;
    studentMethod method = &Student::displayInfo;
    (st2.*method)();
    Student students[3] = {
        Student(),
        Student("Anna", "Biology", 1),
        Student("Sergey", "Physics", 4)
    };
    Student* dynamicStudents = new Student[2];
    dynamicStudents[0] = Student("Olga", "History", 2);
    dynamicStudents[1] = Student("Pavel", "Chemistry", 5);
    cout << "\nИнформация о студентах:" << endl;
    st1.displayInfo();
    st2.displayInfo();
    st3.displayInfo();

    for (int i = 0; i < 3; ++i) {
        students[i].displayInfo();
    }

    for (int i = 0; i < 2; ++i) {
        dynamicStudents[i].displayInfo();
    }

    delete[] dynamicStudents;

    return 0;
}
