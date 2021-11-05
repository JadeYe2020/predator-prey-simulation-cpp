#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main() {
    Student st1; //instantiate 1st student using the default constructor
    string nameOne, nameTwo, nameThree;

    cout << "Enter the first student name:";
    getline(cin, nameOne);
    //update the name in the Student object
    st1.setName(nameOne);

    do
    {
        string coursName;

        cout << "Enter a course name (Enter 'Q' to stop adding courses):\n";
        getline(cin, coursName);

        if(coursName != "Q")
        {
            st1.addCourse(coursName);
        }
        else
            break;
    } while(true);

    //Display the details of 1st student
    cout << "The course details of student 1: " << endl;
    cout << st1;

    //copy the 1st student's course info to create the 2nd student object
    Student st2(st1);
    //Ask for the name
    cout << "\nEnter the second student name:";
    getline(cin, nameTwo);
    st2.setName(nameTwo);

    cout << "\nReset 1st student's course info." << endl;
    st1.reset();
    cout << "Now the current details of student 1: " << endl;
    cout << st1;

    cout << "\nCurrent details of student 2: " << endl;
    cout << st2;

    Student st3; //instantiate the 3rd Student object
    //Ask for the name
    cout << "\nEnter the third student name:";
    getline(cin, nameThree);
    st3.setName(nameThree);

    //Copy the course info from st2 using the assignment operator
    st3 = st2;
    cout << "\nCurrent details of student 3: " << endl;
    cout << st3;

    return 0;
}
