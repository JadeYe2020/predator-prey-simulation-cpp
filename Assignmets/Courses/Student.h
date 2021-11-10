// Student header file
// This is the interface for the Student class
// Created by JadeYe on 11/4/2021.

#ifndef COURSES_STUDENT_H
#define COURSES_STUDENT_H
using namespace std;

class Student
{
    private:
        string name;
    public:
        int numCourses;
        string *courseList;

        //default constructor
        Student(void);
        //constructor with 3 args
        Student(string, int, string*);
        //copy constructor
        Student(const Student&);
        //assignment operator
        Student& operator = (const Student&);
        //destructor
        ~Student(void);

        //set method
        void setName(string);
        //addCourse function
        void addCourse(string);
        //reset function
        void reset(void);
        //output function
        friend ostream& operator<< (ostream&, const Student&);

}; //end class

#endif //COURSES_STUDENT_H