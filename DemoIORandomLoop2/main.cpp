#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>

using namespace std;

//first example
int main() {
    string name;
    cout << "Please enter your full name: ";
    getline(cin, name);
    cout << "Hello " << name << ".\n";
    _getch();
    return 0;
}
