//Note: c++ does not support auto-throwing of system error exceptions
//Always handle validation FIRST programmatically, and only then use exceptions as a BACKUP.

#include <iostream>

#include <exception>
#include <stdexcept>
using namespace std;

//prototypes
void StandardDemo();
void DivByZeroDemo();
void ProgDefinedDemo();

int main() {
//    cout << "Standard Demo" << endl;
//    StandardDemo();
//    cout << "Divide by Zero Demo" << endl;
//    DivByZeroDemo();
    cout << "Programmer Defined Demo" << endl;
    ProgDefinedDemo();

    return 0;
} //end main

int compare (int a, int b) {
    if(a<0 || b<0) {
        throw invalid_argument(" Invalid argument");
    }
} //end method compare

void StandardDemo(){
    try {
        compare(-1, 3);
    }
    catch (const invalid_argument& e) {
        cout << "Exception Happened:" << e.what() << endl;
    }
} //end StandardDemo

double division(int a, int b) {
    if(b == 0) {
        throw "Division by Zero";   //throw just a string
    }
    return (a/b);
} //end method division

void DivByZeroDemo(){
    int x, y;
    double z;

    cout << "Numerator is 10" << endl;
    cout << "Enter Denominator" << endl;
    cin >> y;

    try{
        z = division(x, y);
        cout << "You answer is: " << z << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
} //end method DivByZeroDemo

struct MyException : public exception   //inherits from exception
{
    const string what()
    {
        return "My Exception Happened";
    }
};

void ProgDefinedDemo(){
    try {
        throw MyException();
    }
    //layering exceptions, first the specific one and then a generic one
    catch(MyException& e)
    {
        cout << "My Exception Caught " << endl;
        cout << e.what() << endl;
    }
    catch (exception& e)
    {
        //Other errors
    }
    catch (...){
        //Other errors
    }

}