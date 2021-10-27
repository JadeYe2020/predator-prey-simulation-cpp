#include <iostream>
using namespace std;

class Cat{
    private:
        int itsAge;
    public:
        Cat(){itsAge = 12;}//constructor
        ~Cat(){} //destructor, using tilde sign
    int getAge() const{return  itsAge;}
    void setAge(int age) {itsAge = age;}

}; //end class Cat

int main() {
    Cat otherCat = Cat(); //a local instantiation, NO "new" keyword but needs parenthesis
    cout << "Other cat is " << otherCat.getAge() << endl;
    Cat *pCharlie = new Cat; //instantiation on heap memory: "new" keyword, but NO parenthesis
    //needs to dereference the pointer and then call the dot operator
    cout << "Charlie is " << (*pCharlie).getAge() << endl;

    pCharlie->setAge(13);
    cout << "Charlie is " << pCharlie->getAge() << endl; //using the arrow operator

    //delete the object
    delete pCharlie;

    return 0;
} //end main
