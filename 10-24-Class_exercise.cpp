#include <iostream>

using namespace std;

class DayofYear {
public:
    int day;
    int month;
    void output();


};

void DayofYear::output(){
    cout << "The month is " <<month << " and the day is " << day;
}

int main()

{
    DayofYear birthday;
    birthday.day =17;
    birthday.month =10;
    birthday.output();
    today.day =24;
    today.month =10;
    today.output();
    return 0;



}






