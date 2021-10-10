#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

string askForFilename();
string storeLine(string fileName, int lineNum);

int main() {
    string inFileName;
    cout << "First, choose a cpp file to convert." << endl;
    inFileName = askForFilename();

    string outFileName;
    cout << "And now, decide what html file you want to save it as." << endl;
    outFileName = askForFilename();

    ifstream fileIn;
    string line;
    fileIn.open(inFileName + ".cpp"); //try to open the file
    if(!fileIn.fail()) {
        cout << "The file content shows as below: " << endl;
        while(!fileIn.eof()){
            getline(fileIn, line);
            cout << line << endl;
        }
        fileIn.close();
        cout << "The file has been closed." << endl;
    }
    else {
        cout << "Input file failed to open." << endl;
    }


//    cout << storeLine(inFileName, 3) << endl;

    return 0;
}

string askForFilename() {
    string fileName;

    cout << "Please enter the file name. e.g. 'c:\\bobFile'" << endl;
    getline(cin, fileName);

    //regex pattern for valid filenames (https://www.geeksforgeeks.org/regex-regular-expression-in-c/)
    //(https://docs.microsoft.com/en-us/windows/win32/fileio/naming-a-file)
    regex pattern("[a-zA-Z]:(\\\\[^\\<\\>:\"/\\\\|\\?\\*]+[^\\<\\>:\"/\\\\|\\?\\*\\.])+");

    if(!regex_match(fileName, pattern)) {
        cout << "The file path is not valid." << endl;
        fileName = askForFilename();
    }
    else
        return fileName;
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
