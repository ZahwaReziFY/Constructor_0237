#include <iostream>
using namespace std;

class Student
{
private:
    static int studentTotal;

public:
    string name;
    string status;
    int age;

    Student(string pName, int pAge) //parameter pName dan pAge
    {
        name = pName;
        age = pAge;
        status = "New Student";
        ++studentTotal;
        cout << name << "Created" << "Status" << status << endl;
        cout << endl;
    }

    ~Student()
    {
        cout << name << "Destroyed" << endl;
        --studentTotal;
        cout << endl;
    }

    static int getStudentTotal()
    {
        return studentTotal;
    }

    static void setSudentTotal(int a)
    {
        studentTotal = a;
    }
};

int Student::studentTotal = 0;

int main()
{

    cout << "Student total is " << Student::getStudentTotal() << endl;

    Student st1("Maman", 40);
    Student st2("Agus", 34);

    Student::setSudentTotal(10);

    cout << "Student total is " << Student::getStudentTotal() << endl;

    {
        Student st3("Budi", 19);
        Student st4("Caca", 21);
        cout << "Student total is " << Student::getStudentTotal() << endl;
    }

    cout << "Student total is " << Student::getStudentTotal() << endl;
}