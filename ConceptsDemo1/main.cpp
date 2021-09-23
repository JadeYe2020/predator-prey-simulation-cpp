#include <iostream>
//C++ Concepts Demo
//Demo of Enumerated Constants, Type Definitions, "Magic Formula" for cout and decimals
#include <iostream>
using namespace std;

//prototypes
void demoOne();
void demoTwo();
void demoThree();
void demoFour();
void demoFive();
void demoSix();
void demoSeven();//enum strings

//enumerated constants
enum {E1,E2,E3};//Demo 1    //an enum without a name
enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};//Demo 2
enum State {Working = 1, Failed = 0, Freezed = 0};//Demo 3  //override the indexed numbers
enum {P1,P2,P3,};//Demo 7
string puppies[]={"Doodle","Pug","Beagle"};//Demo 7

int main() {
    demoOne();
    demoTwo();
    demoThree();
    demoFour();
    demoFive();
    demoSix();
    demoSeven();
    return 0;
}
void demoOne(){
    cout << "DEMO #1" << endl;
    cout <<  E1 << endl;    //Index numbers will be printed out.
    cout <<  E2 << endl;
    cout <<  E3 << endl;
}
void demoTwo(){
    cout << "DEMO #2" <<endl;
    enum week day;  //can create a variable of a specific enum item.
    day = Wed;
    cout << "Wednesday is the: "<<day<<" day of the week";
}
void demoThree(){
    cout << "DEMO #3" <<endl;
    cout << Working << endl;
    cout << Failed << endl;
    cout << Freezed << endl;
}
void demoFour(){ //assign name to type definition then use name for declarations
    cout << "DEMO #4" << endl;
    typedef int* IntPtr;    //make a new alias for a datatype
    IntPtr pointer1,pointer2;
}
void demoFive(){    //Format the stream
    cout.setf(ios::fixed);  //When floatfield is set to fixed, floating-point values are written
    // using fixed-point notation: the value is represented with exactly as many digits in the decimal part
    // as specified by the precision field (precision) and with no exponent part.

    cout.setf(ios::showpoint);  //the decimal point is always written for floating point values
    // inserted into the stream (even for those whose decimal part is zero).
    //to match the precision set for the stream

    cout.precision(2);

    double price = 22;
    cout << "The price is $" << price << endl;
    price = 42.43333;
    cout << "The price is $" << price << endl;
    price = 42.4363;
    cout << "The price is $" << price << endl;

    //The settings is in a global scope. Needs to be reset at the end.
    cout.unsetf(ios::fixed); //resets cout to default
    cout.unsetf(ios::showpoint);//resets cout to default

}

void demoSix(){//proves resets in demoFive work
    double cost = 66;
    cout << "Cost is: $"<<cost<<endl;
}

void demoSeven()//enum strings
{
    //turns out that there is no built in method, so some form of
    //mapping between a data structure hash map, list, array, etc.)
    //or other method using classes and or macros is required. e.g.

    cout << puppies[P1]<<endl;//array and enums in parallel.

}
