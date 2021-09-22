#include <iostream>

#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main() {
    string strAge;
    int age;
    stringstream ss;
    bool valid = true;

    while(true) {
        cout << "Enter your age:";
        cin >> strAge;
        for(int i=0; i<strAge.length(); i++){
            if(!isdigit(strAge[i])){
                valid = false;
                cout << "Input is NOT valid" << endl;
                break; // out of the for loop.
            }

            //convert str to int
            ss << strAge;
            ss >> age;
        }//end for loop
        if(valid) {
            cout << "Age is valid: " << age << endl;
            break; //out of the while loop
        }
        else {
            //reset the flag
            valid = true;
        }

    }//end while

    return 0;
}
