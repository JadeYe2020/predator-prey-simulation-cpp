#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string storeLine(string fileName, int lineNum);

int main() {
    string fileName;

    cout << "Please enter the file name to convert. e.g. 'c:\\bobFile'" << endl;
    getline(cin, fileName);

    //NEED A REGEX HERE TO VALIDATE

    cout << storeLine(fileName, 3) << endl;

    return 0;
}

string storeLine(string fileName, int lineNum) {
    string line;
    ifstream fileIn;

    fileIn.open(fileName);

    if(!fileIn.fail()) {
        int lineCount = 0;

        while (!fileIn.eof() || lineCount < lineNum) {
            getline(fileIn, line);

            lineCount++;
        }

        return line;
    }
    else {
        cout << "Failed to open the file." << endl;
        return "";
    }
}
