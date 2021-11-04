//Custom String Class - demo of rule of three

#include <iostream>
#include <ostream>
#include <cstring>
using namespace std;

class MyString
{
    char* str;

    public:
        //no arg constructor aka default
        MyString();
        //constructor with one argument
        MyString(char* val);
        //Copy constructor
        MyString(const MyString& source);
        //Move constructor
        MyString(MyString&& source);
        //Destructor
        ~MyString()
        {
            cout << "Destructor Fired" << endl;
            if(str != NULL)
                delete []str;
        };

}; //end Class MyString

//Implementations for class
//constructor no args
MyString::MyString()
    :str{nullptr} //initialization section
{
    cout << "Default Constructor Fired" << endl;
    str = new char[1];
    str[0] = '\0';
}

//Constructor with one char* arg
MyString::MyString(char* val) {
    cout << "Constructor with char* arg Fired" << endl;
    if(val == nullptr){
        str = new char[1];
        str[0] = '\0';
    }
    else{
        str = new char[strlen(val)+1]; //+1 for null terminating character
        strcpy(str, val);
        cout << "The string passed is: " << str << endl;
    }
}

//copy constructor
MyString::MyString(const MyString& source)
{
    cout << "Copy Constructor Fired" << endl;
    str = new char[strlen(source.str)+1];
    strcpy(str, source.str);
}

//Move Constructor
MyString::MyString(MyString&& source)
{
    cout << "Move Constructor Fired" << endl;
    str = source.str;
    source.str = nullptr;
}

int main() {
    //demo default
    MyString a;
    //demo one arg constructor
    MyString b("Hello");
    //demo copy constructor
    MyString c(a);
    char temp[] = "World";

    //demo move constructor
    MyString d{MyString{temp}};

    return 0;
} //end main
