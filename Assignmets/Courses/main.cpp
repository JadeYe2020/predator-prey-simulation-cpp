#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main() {
    Student st1; //instantiate 1st student using the default constructor
    string nameOne;

    cout << "Enter student name:";
    cin >> nameOne;
    //update the name in the Student object
    st1.setName(nameOne);

    do
    {
        string coursName;

        cout << "Enter a course name (Enter 'Q' to stop adding courses):";
        cin >> coursName;

        if(coursName != "Q")
        {
            st1.addCourse(coursName);
            st1.numCourses ++;
        }
        else
            break;
    } while(true);

    //Display the details of 1st student
    cout << st1;

    return 0;
}
