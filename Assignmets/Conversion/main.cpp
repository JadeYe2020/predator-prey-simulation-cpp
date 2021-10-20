#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <exception>

using namespace std;

string askForFilename();
void writeNew(string outFileName, string line);
void appendLine(string outFileName, string line);
string findAndReplace(string line, string oldStr, string newStr);

//Create a struct for the programmer defined exception
struct MyException : public exception
{
    const string what()
    {
        return "Output file failed to open. Nothing got appended.";
    }
};

int main() {
    string inFileName;
    cout << "First, choose a cpp file to convert." << endl;
    inFileName = askForFilename()+".cpp";   //append the file type to complete the filename for the user

    string outFileName;
    cout << "And now, decide what html file you want to save it as." << endl;
    outFileName = askForFilename()+".html";

    ifstream fileIn;
    string lineRead;
    try
    {
        fileIn.open(inFileName); //try to open the file

        if(fileIn.fail()) {
            //to throw a ifstream failure (https://www.cplusplus.com/reference/ios/ios/exceptions/)
            fileIn.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        }
        else {
            try { //try to start writing the out file with the first <PRE> tag
                writeNew(outFileName, "<PRE>");
            }
            catch (const char* msg){
                cout << msg << endl;
            }
            catch (exception& e) {
                cout << "An unknown error happened" << endl;
            }

            while(!fileIn.eof()){
                getline(fileIn, lineRead);

                //convert the chevrons line by line
                string lineToWrite = findAndReplace(lineRead, "<", "&lt;");
                lineToWrite = findAndReplace(lineToWrite, ">", "&gt;");

                try { //try to copy the line into fileOut
                    appendLine(outFileName, lineToWrite);
                }
                catch (MyException& myE) {
                    cout << myE.what() << endl;
                    break;
                }
                catch (exception& e) {
                    cout << "An unknown error happened" << endl;
                    break;
                }
            } //end while
            fileIn.close();

            try { //lastly, try to add the end PRE tag.
                appendLine(outFileName, "</PRE>");

                cout << "Congratulations! The file has been converted." << endl;
            }
            catch (MyException& myE) {
                cout << myE.what() << endl;
            }
            catch (exception& e) {
                cout << "An unknown error happened" << endl;
            }
        }//end else
    }//end outer try
    catch (ifstream::failure& fe) {
        cout << "Input file failed to open." << endl;
    }
    catch (exception& e) {
        cout << "An unknown error happened when trying to open the file." << endl;
    }

    return 0;
}

string askForFilename() {
    string fileName;

    //Ask the user to enter the file name as the example
    cout << "Please enter the file name. e.g. 'c:\\bobFile'" << endl;
    getline(cin, fileName);

    //regex pattern for valid filenames (https://www.geeksforgeeks.org/regex-regular-expression-in-c/)
    //(https://docs.microsoft.com/en-us/windows/win32/fileio/naming-a-file)
    regex pattern("[a-zA-Z]:(\\\\[^\\<\\>:\"/\\\\|\\?\\*]+[^\\<\\>:\"/\\\\|\\?\\*\\.])+");

    if(!regex_match(fileName, pattern)) {
        cout << "The file path is not valid." << endl;
        //if the filename is apparently illegal, then call the function itself again to ask the user to re-enter another one
        // until an valid filename is input.
        fileName = askForFilename();
    }
    else
        return fileName;
}

void writeNew(string outFileName, string line) {
    ofstream  fileOut;
    fileOut.open(outFileName);  //not for appending

    if(fileOut.fail()){
        throw "Output file failed to open. Nothing got written.";
    }
    else {
        fileOut << line << endl;
        fileOut.close();
    }
}

void appendLine(string outFileName, string line) {
    ofstream  fileOut;
    fileOut.open(outFileName, ios::app); //try to open the file to append

    if(fileOut.fail()) {
        throw MyException();
    }
    else {
        fileOut << line << endl;
        fileOut.close();
    }
}

string findAndReplace(string line, string oldStr, string newStr)
{
    //(https://www.geeksforgeeks.org/regex-regular-expression-in-c/)
    regex p(oldStr);

    return regex_replace(line, p, newStr);
}