#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string fileName;

    cout << "Please enter the file name to convert. e.g. 'c:\\bobFile'" << endl;
    getline(cin, fileName);
    cout << fileName << endl;

    return 0;
}
