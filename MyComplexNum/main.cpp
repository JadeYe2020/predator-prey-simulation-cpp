#include <iostream>
#include <sstream>
using namespace std;

class ComplexNumber
{
    private:
        double real;
        double imaginary;

    public:
        ComplexNumber()  //default constructor
            :real(), imaginary() {}

        ComplexNumber(double real, double imaginary) //constructor with arguements
            :real(real), imaginary(imaginary) {}

        ComplexNumber(string s) //constructor for string e.g. "a+bi"
        {
            //parse routine goes here
            this->real = 4; //hard coded stub for testing
            this->imaginary = 2;
        }

        //operator overloading:
        ComplexNumber operator+ (ComplexNumber &rightObj)
        {
            return ComplexNumber(this->real + rightObj.real, this->imaginary + rightObj.imaginary);
        }

        //code other operator overloads here

        void print() //"a+bi" //dirty method
        {
            cout << this->real << " + " << this->imaginary << "i" << endl;
        }

        string toString() //clean method
        {
            stringstream strStream;
            string s1, s2;

            //next 5 lines are used to do conversions from double to string
            strStream << this->real; //places in stream
            strStream >> s1; //rec back as a string
            strStream.clear(); //clear the stream
            strStream << this->imaginary;
            strStream >> s2;

            //create a string from above in a+bi format
            return (s1 + " + " + s2 + "i");
        } //end toString

        //define friend functions
        friend void operator>> (istream &input, ComplexNumber &num);
        friend ostream& operator<< (ostream &output, ComplexNumber &num);

}; //end class

//implementation of friend functions - must be outside the class
void operator>> (istream &input, ComplexNumber &num)
{
    string str;
    getline(input, str); //assigns the input string to string variable
    num = ComplexNumber(str); //to provide a+bi to the string type constructor
}

ostream& operator<< (ostream &output, ComplexNumber &num)
{
    output << num.real << " + " << num.imaginary << "i";
    return output;
}

int main() {
    cout << "test default constructor and dirty print function: " << endl;
    ComplexNumber cn1; //use of default constructor
    cn1.print();

    cout << "test of constructor with args and toString function: " << endl;
    ComplexNumber cn2(5, 8); //use of the constructor with 2 arguments
    cout << cn2.toString() << endl;

    cout << "test of string constructor and toString function: " << endl;
    ComplexNumber cn3("9+9i"); //use of the string constructor - stubbed
    cout << cn3.toString() << endl;

    cout << "test of + operator and toString function: " << endl;
    ComplexNumber cn4 = cn2 + cn3;
    cout << cn4.toString() << endl;

    cout << "test of input operator: " << endl;
    //note: have the overloaded input call a validation method and execute a cin.fail if the string is not valid - loop and ask again
    ComplexNumber cn5;
    cout << "Enter a complex number in a+bi format - note stubbed" << endl;
    cin >> cn5;
    cout << cn5.toString() << endl;
    cout << "Test Complete" << endl;

    return 0;
} //end main
