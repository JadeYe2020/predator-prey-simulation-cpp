//This is a demonstration driver for MyOwnMath class

#include <iostream>
#include <conio.h>
#include "MyOwnMath.h"

using namespace std;

int main() {
    int ans1 = 0;
    int ans2 = 0;
    int input = 0;
    MyOwnMath myOwnMath;

    cout << "Enter an int 1-9" << endl;
    cin >> input;
    ans1 = myOwnMath.square(input);
    ans2 = myOwnMath.add(input, input);
    cout << "You number squared is: " << ans1 << endl;
    cout << "You number added to self is: " << ans2 << endl;

    return 0;
}
