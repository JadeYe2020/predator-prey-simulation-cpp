#include <iostream>

#include <string>
#include <cctype>
using namespace std;

int main() {
    bool rejected = false;
    string name;

    while (true){
        cout << "Enter your name:";
        getline(cin, name);

        for (int i = 0; i < name.length() && !rejected; i++){
            if(isalpha(name[i]))
                continue;
            if(name[i]==' ')
                continue;
            rejected = true; //otherwise reject
        }// end for loop

        if(!rejected){
            cout << "Input is valid." << endl;
            break;
        }
        else{
            cout << "Input is NOT valid." << endl;
            rejected = false; //reset
        }
    }//end while

    return 0;
}
