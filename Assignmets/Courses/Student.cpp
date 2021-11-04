// This is the implementation file
// Created by JadeYe on 11/4/2021.

#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

//default constructor
Student::Student(): name(""), numCourses(0)
{
    cout << "Default Constructor Fired" << endl;
    courseList = new string[numCourses]; //declare the array on heap
};

//constructor with 3 arguments
Student::Student(string name, int numCourses, string *cArray)
{
    this->name = name;
    this->numCourses = numCourses;
    this->courseList = cArray;
}

//Copy Constructor
Student::Student(const Student& toBeCopied)
{
    cout << "Copy Constructor Fired" << endl;
    //numCourses value copied and stored.
    numCourses = toBeCopied.numCourses;

    courseList = toBeCopied.courseList;
//    //to copy and store each element of the courseList.
//    for(int i=0; i<numCourses; i++)
//    {
//        courseList[i] = toBeCopied.courseList[i];
//    }
    //no name set yet. empty string by default.
    name = "";
}

//assignment operator
Student& Student::operator= (const Student& toBeCopied)
{
    cout << "Assignment Operator Called" << endl;
    if(numCourses != toBeCopied.numCourses)
    {
        //if the size of the 2 arrays are not equal, delete the one on the left side
        delete []courseList;
        // and replace it with a new array with the same size as the right side
        this->numCourses = toBeCopied.numCourses;
        courseList = new string[this->numCourses];
    }
    //copy and store each element
    for(int i=0; i<numCourses; i++)
    {
        courseList[i] = toBeCopied.courseList[i];
    }

    return *this;
}

//destructor
Student::~Student()
{
    cout << "Destructor Fired" << endl;
    if(courseList != NULL) //non-null test
        delete []courseList;
    courseList = NULL; //assign null
}

//set method
void Student::setName(string name)
{
    this->name = name;
}

//addCourse function
void Student::addCourse(string course)
{
    //create a temp array to have space for one more element
    string *temp = new string[numCourses+1];
    //copy and store each element of the original array
    for(int i=0; i<numCourses; i++)
    {
        temp[i] = courseList[i];
    }
    //put the new string into the temp array
    temp[numCourses] = course;
    //delete the original array
    delete []courseList;
    //create a new courseList and have the data copied back to it
    courseList = temp;
    //increment numCourse
    numCourses ++;
    cout << "Array size has been increased by one." << endl;
}

//reset function
void Student::reset()
{
    numCourses = 0;
    //delete the courseList
    delete []courseList;
    //create an empty courseList
    courseList = new string[numCourses];
}

//output function. overload <<
ostream& operator<< (ostream &output, const Student &st)
{
    string str = "Student Name: " + st.name + "\nEnrolled in " + to_string(st.numCourses) + " course(s): \n";
    //use a for loop to add the courses into the string
    for(int i=0; i<st.numCourses; i++)
    {
        str += st.courseList[i] + "\n";
    }
    output << str;

    return output;
}