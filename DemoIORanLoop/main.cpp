#include <iostream>
//extra libraries:
#include <conio.h>
//#include <termios.h>
#include <string>
#include <ctime>
#include <sstream>

//specify the namespace for the libraries above, "std" by default
using namespace std;

//int main() {
////    cout << "Hello, World!" << endl;
//    string name;    //build-in string type, lowercase "s"
//    cout << "Please enter your first name: ";   //use "cout <<" to output strings
//    getline(cin, name); //ask for user input, and assign the value to "name" var
//    cout << "Hello, " << name << ".\n"; //concat using "<<"
//    _getch();   //get-character function to pause for input
////    getchar();
//
//    return 0;
//}

//int main () {
//    string mystr;
//    float price = 0;
//    int quantity = 0;
//
//    cout << "Enter price: ";
//    getline(cin, mystr);
////    price = mystr;  //conversion error str to float
//    stringstream (mystr) >> price;  //function from sstream library, automatically casts the value into the type needed
//    cout << "Enter quantity: ";
//    getline(cin, mystr);
//    stringstream (mystr) >> quantity;
//    cout << "Total cost: " << price*quantity << endl;
//    getchar();
//
//    return 0;
//}   //end main

int main() {
    for(int i=0; i<100; i++)
    {
//        cout << i+1 << " " << rand() << endl;   //rand() generates random numbers.
        cout << i+1 << " " << 1 + rand()%10 << endl;    //rand()%10 generates numbers between 0~9
    }

    return 0;
} //end main