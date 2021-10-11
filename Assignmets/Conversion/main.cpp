#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

string askForFilename();
void appendLine(string outFileName, string line);
string convertAnglebrackets(string line);
void printFile(string inFileName);
int numOfLines(string inFileName);
string storeLine(string fileName, int lineNum);

int main() {
    string inFileName;
    cout << "First, choose a cpp file to convert." << endl;
    inFileName = askForFilename()+".cpp";

    string outFileName;
    cout << "And now, decide what html file you want to save it as." << endl;
    outFileName = askForFilename()+".html";

    ifstream fileIn;
    string lineRead;
    fileIn.open(inFileName); //try to open the file
    if(!fileIn.fail()) {
        //first need to add the first <PRE> tag
        appendLine(outFileName, "<PRE>");

        while(!fileIn.eof()){
            getline(fileIn, lineRead);
            //convert the line
            string lineToWrite = convertAnglebrackets(lineRead);
            //copy the line into fileOut
            appendLine(outFileName, lineToWrite);
        }
        fileIn.close();

        //lastly, add the end PRE tag.
        appendLine(outFileName, "</PRE>");
        cout << "Congratulations! The file has been converted." << endl;
    }
    else {
        cout << "Input file failed to open." << endl;
    }

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

void appendLine(string outFileName, string line) {
    ofstream  fileOut;
    fileOut.open(outFileName, ios::app); //try to open the file to append

    if(!fileOut.fail()){
        fileOut << line << endl;
        fileOut.close();
    }
    else
        cout << "Output file failed to open." << endl;
}

string convertAnglebrackets(string line) {
    string converted;

    regex pForLeft("<");
    regex pForRight(">");

    //https://www.geeksforgeeks.org/regex-regular-expression-in-c/
    converted = regex_replace(line, pForLeft, "&lt;");
    converted = regex_replace(converted, pForRight, "&gt;");

    return converted;
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

void printFile(string inFileName) {
    ifstream fileIn;
    string lineRead;
    fileIn.open(inFileName); //try to open the file
    if(!fileIn.fail()) {
        cout << "The file content shows as below: " << endl;
        while(!fileIn.eof()){
            getline(fileIn, lineRead);
            cout << lineRead << endl;
        }
        fileIn.close();
        cout << "The file has been closed." << endl;
    }
    else {
        cout << "Input file failed to open." << endl;
    }
}

int numOfLines(string inFileName) {
    ifstream fileIn;
    string line;
    int lineCount = 0;
    fileIn.open(inFileName); //try to open the file
    if(!fileIn.fail()) {
        while(!fileIn.eof()){
            getline(fileIn, line);
            lineCount++;
        }
        fileIn.close();
        return lineCount;
    }
    else {
        cout << "Input file failed to open." << endl;
        return 0;
    }
}