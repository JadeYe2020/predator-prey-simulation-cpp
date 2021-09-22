#include <iostream>

#include <regex>
#include <string>

using namespace std;

int main() {
    string input;
    regex exp("(\\+|-)?[[:digit:]]+");
    //if input is correct ask for another number
    while(true){
        cout << "Enter the input or q to exit:";
        cin >> input;

        if (!cin){  //if no input
            break;
        }
        if (input == "q"){
            break;
        }
        if (regex_match(input, exp)){
            cout << "Input is an integer" << endl;
        }
        else {
            cout << "Input is NOT valid" << endl;
        }
    }//end while

    return 0;
}
