#include <iostream>
#include <string.h>

using namespace std;

class student {
public:
    string name;
    int age;
    double gpa;
    string major;
    void output();

};

void student::output(){
    cout << " My name is " << name << " my major is " << major<< " my age is "<< age << " and my GPA is "<< gpa<< endl ;
}

int main()

{
    student Lukas;
    Lukas.name = "Lukas";
    Lukas.age =19;
    Lukas.gpa =3.6;
    Lukas.major ="Computer Engineering";
    Lukas.output();

    student Alex;
    Alex.name = "Alex";
    Alex.age = 19;
    Alex.gpa = 3.8;
    Alex.major = "Computer Engineering";
    Alex.output();

    student Massimo;
    Massimo.name = "Massimo";
    Massimo.age = 19;
    Massimo.gpa = 3.9;
    Massimo.major = "Electrical Engineering";
    Massimo.output();

    student Adael;
    Adael.name = "Adael";
    Adael.age = 19;
    Adael.gpa = 3.9;
    Adael.major = "Electrical Engineering";
    Adael.output();

    student John;
    John.name = "John";
    John.age = 19;
    John.gpa = 3.9;
    John.major = "Electrical Engineering";
    John.output();


    return 0;

}






