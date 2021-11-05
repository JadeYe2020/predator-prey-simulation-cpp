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
        Student();
        //constructor with 3 args
        Student(string name, int numCourses, string *cArray);
        //copy constructor
        Student(const Student& toBeCopied);
        //assignment operator
        Student& operator = (const Student& toBeCopied);
        //destructor
        ~Student();

        //set method
        void setName(string name);
        //addCourse function
        void addCourse(string course);
        //reset function
        void reset();
        //output function
        friend ostream& operator<< (ostream &output, const Student &st);

}; //end class

#endif //COURSES_STUDENT_H