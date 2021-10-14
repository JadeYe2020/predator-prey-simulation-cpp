#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

string askForFilename();
void appendLine(string outFileName, string line);
string findAndReplace(string line, string oldStr, string newStr);

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
            string lineToWrite = findAndReplace(lineRead, "<", "&lt;");
            lineToWrite = findAndReplace(lineToWrite, ">", "&gt;");
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

string findAndReplace(string line, string oldStr, string newStr)
{
    //(https://www.geeksforgeeks.org/regex-regular-expression-in-c/)
    regex p(oldStr);

    return regex_replace(line, p, newStr);
}