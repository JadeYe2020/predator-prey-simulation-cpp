#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

string storeLine(string fileName, int lineNum);

int main() {
    string fileName;

    cout << "Please enter the file name to convert. e.g. 'c:\\bobFile'" << endl;
    getline(cin, fileName);

    //regex pattern for valid filenames (https://www.geeksforgeeks.org/regex-regular-expression-in-c/)
    regex pattern("[a-zA-Z]:(\\\\[^\\<\\>:\"/\\\\|\\?\\*]+[^\\<\\>:\"/\\\\|\\?\\*\\.])+");

    if(regex_match(fileName, pattern)) {
        cout << "Filename is legal" << endl;
    }
    else
        cout << "Filename is invalid." << endl;

//    cout << storeLine(fileName, 3) << endl;

    return 0;
}

string storeLine(string fileName, int lineNum) {
    string line;
    ifstream fileIn;

    fileIn.open(fileName);

    if(!fileIn.fail()) {
        int lineCount = 0;

        while (!fileIn.eof() && lineCount < lineNum) {
            getline(fileIn, line);

            lineCount++;
        }

        fileIn.close();

        if (lineCount < lineNum) {
            cout << "The file has fewer than " << lineNum << " lines. Nothing will be stored." << endl;
            return "";
        }
        return line;
    }
    else {
        cout << "Failed to open the file." << endl;
        return "";
    }
}
