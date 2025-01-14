#include <iostream>
#include <string.h>

using namespace std;

class student {
private:
    int id;
    string name;
    int age;
    string major;

public:
    void setid(int newID);
    void setname ( string newName);
    void setage (int newage);
    void setmajor (string newmajor);
    int getId();
    string getname();
    int getage();
    string getmajor();


};
void student::setid(int newID){
    id= newID;
}

int student::getId (){
    return id;
}

void student::setname(string newName){
    name= newName;
}

string student::getname()
{
    return name;
}

void student::setage(int newage){
    age= newage;
}

int student::getage(){
    return age;
}

void student::setmajor(string newmajor){
    major= newmajor;
}

string student::getmajor()
{
    return major;
}


int main()
{
    student std1;
    std1.setid(12345);
    std1.setname("Paul");
    std1.setage(19);
    std1.setmajor("Electrical Engineering");
    cout<< std1.getId() << " "<< std1.getname()<< " "<<std1.getage()<< " "<<std1.getmajor();
    return 0;
}

