#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main() {
    Student st1; //instantiate 1st student using the default constructor
    string nameOne, nameTwo, nameThree;

    cout << "Enter student #1's name:";
    getline(cin, nameOne);
    //update the name in the Student object
    st1.setName(nameOne);

    cout << "Enter course names for student #1. Type 'Q' when done." << endl;
    do
    {
        string coursName;

        cout << "Course name:";
        getline(cin, coursName);

        if(coursName != "Q")
        {
            st1.addCourse(coursName);
        }
        else
            break;
    } while(true);

    //Display the details of 1st student
    cout << "\nStudent #1's information: " << endl;
    cout << st1;

    //Ask for the name of student #2
    cout << "Enter student #2's name:";
    getline(cin, nameTwo);
    //copy the 1st student's course info to create the 2nd student object
    Student st2(st1);
    //set the name using the input value
    st2.setName(nameTwo);

    cout << "Student #2's information - obtained with the copy constructor:" << endl;
    cout << st2;

    cout << "Student #1's information after being reset: " << endl;
    //reset st1
    st1.reset();
    cout << st1;

    cout << "Student #2's information again - an example of a deep copy: " << endl;
    cout << st2;

    Student st3; //instantiate the 3rd Student object
    //Ask for the name
    cout << "Enter the third student name:";
    getline(cin, nameThree);
    st3.setName(nameThree);

    //Copy the course info from st2 using the assignment operator
    st3 = st2;
    cout << "\nStudent #3's information - obtained with the assignment operator:" << endl;
    cout << st3;

    return 0;
}
