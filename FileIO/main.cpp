#include <iostream>

#include <string>
#include <fstream>

using namespace std;

//prototypes
void demoOpenCloseStream();
void demoOpenPrint();
void demoOpenWrite();

int main() {
    cout << "Begin fileIO Demonstration" << endl;
//    cout << "Begin Open Close Streams Demo" << endl;
//    demoOpenCloseStream();
//    cout << "Begin Open Print Streams Demo" << endl;
//    demoOpenPrint();
    cout << "Begin Open Write Streams Demo" << endl;
    demoOpenWrite();
    cout << "End fileIO Demonstration" << endl;
    return 0;
}   //end main

void demoOpenCloseStream(){
    cout << "Files Open" << endl;

    //declare stream objects
    ifstream inStream;
    ofstream outStream;
    //connect files to stream objects
    inStream.open("infile.txt");
    outStream.open("outfile.txt");
    //a shorter version of above:
    ifstream inStream2("infile.txt");
    //close resources
    inStream.close();
    outStream.close();
    inStream2.close();
    cout << "File closed" << endl;
}

void demoOpenPrint(){
    string line;
    ifstream myFileIn;
    //You may use either .fail() or the .is_open() method of the file stream object
    myFileIn.open("myFileIn.txt");
    if(myFileIn.is_open()) // or if(myFileIn.fail())
    {
        cout << "File Open" << endl;
        while (!myFileIn.eof()) {   //eof: end of file
            getline(myFileIn, line);
            cout << line << endl;
        }
        myFileIn.close();
        cout << "File Closed" << endl;
    }
    else {
        cout << "Input file failed to open" << endl;
    }
}//end method
void demoOpenWrite(){
    ofstream myFileOUt;
    //to append to a file - use ios::app
    myFileOUt.open("myFileOut.txt", ios::app);  //open for append

    if(!myFileOUt.fail()){
        myFileOUt << "stuff" << " and more stuff" << endl;
        myFileOUt.close();
        cout << "File Closed" << endl;
    } else{
        cout << "Output File failed to open" << endl;
    }
}