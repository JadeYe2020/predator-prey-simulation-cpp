#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
//    int size;
//    int myArray[size]; //error variable size
//    int myArray2[10]; //fixed size
//    const int SIZE = 10;
//    int myArray3[SIZE]; //use of const modifier

//    const int MAX = 3;
//    int nonD[MAX];
//    int c = 0;
//
//    //read into the above array
//    cout << "Enter an integer:" << endl;
//
//    while(cin >> nonD[c]) //if it reads the return as true
//    {
//        c++;
//        if (c<5)
//            cout << c << " elements used" << " max is: " << MAX << endl;
//        else
//            cout << "at max - next will exceed array size" << endl;
//
//        for(int i=0; i<MAX; i++)
//        {
//            cout << nonD[i] << endl;
//        }
//
//        cout << "Enter an Integer:" << endl;
//    }//end while
    //notice that the above will allow you to exceed array bounds

    //"Dynamic Array" as in declared in dynamic memory, not that its size can change
    //This program starts with a small array and then adds more space by declaring a new array that's larger
//    int max = 3; // not a constant value
//    int *dynArray = new int[max]; //"new" declares a memory in heap
//    int c=0;
//
//    cout << "Enter an integer:" << endl;
//    while(cin >> dynArray[c])
//    {
//        c++;
//        if(c>=max) // when the array is full
//        {
//            max = max *2;   //double the size
//            int *temp = new int[max]; //create a temp array to hold data
//            for(int i=0; i<c; i++)
//            {
//                temp[i] = dynArray[i]; // copy elements into the larger temp
//            }
////            delete dynArray; //will cause memory leak b/c it only deletes the pointer pointing to the first element
//                delete []dynArray; //tells compiler it is dealing with an array
//
//                //create a new dynArray and have the data copied back to it
//                dynArray = temp;
//                cout << "array size is: " << max << " " << max-c << " now available"<< endl;
//        }//end if
//        cout << "Enter an integer:" << endl;
//
//    }//end while

    //declared with only a name
    vector<float> v;
    cout << v.size() << endl;

    //declared with the num of elements
    vector<float> v2(10);
    cout << v2.size() << endl;
    //to resize
    v2.resize(5);
    cout << v2.size() << endl;

    //declared with braces and commas
    vector<float> v3 = {1.1, 2.2, 3.3, 4.4};
    cout << "size: " << v3.size() << endl;

    v3.push_back(5.5); //append one element
    cout << "size: " << v3.size() << endl;

    for(int i=0; i< v3.size(); i++)
    {
        cout << v3[i] << endl;
    }

    //display the first, the index 2 and the last element
//    cout << v3.front() << " " << v3.at(2) << " " << v3.back() << endl;

    v3.pop_back(); // drops the last element

    //vetor iterator
    vector<float>::iterator iter;
    for(iter = v3.begin(); iter != v3.end(); iter++)
    {
        cout << *iter << endl; //needs to use the dereference operator
    }

    return 0;
}//end main
