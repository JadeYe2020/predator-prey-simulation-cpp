// Student header file
// This is the interface for the Student class
// Created by JadeYe on 11/4/2021.

#ifndef COURSES_STUDENT_H
#define COURSES_STUDENT_H

#include <string>
using namespace std;

class Student
{
    private:
        string name;
        int numCourses;
        string *courseList;

    public:
        //default constructor
        Student(void);
        //constructor with 3 args

        //copy constructor
        Student(const Student&);
        //assignment operator
        Student& operator = (const Student&);
        //destructor
        ~Student(void);

        //set method
        string setName(string);
        //add function
        void add(string);
        //reset function
        void reset(const Student&);
        //output function
        friend ostream& operator<< (ostream &output, ComplexNumber &num);

}; //end class

#endif //COURSES_STUDENT_H