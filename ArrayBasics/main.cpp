#include <iostream>
#include <conio.h>
#include <array>

using namespace std;

//prototypes
void addTen(int *p, int); //p points to where array begins in memory, int will be the num of elements

int main() {
//    //1d array
//    int a[3];
//    a[0]=0;
//    a[1]=1;
//    a[2]=2;
//
//    int b[] = {0, 1, 2}; //declare and fill at the same time - initializer
//    array<int, 6> myArray = {0,1,2}; //will auto-fill with 0s
//
//    for(int i=0; i<6; i++)
//    {
//        cout << myArray[i];
//    }

//    //2d array demo
//    int my2DArray[][3]={{0, 100, 200},{1, 300, 400},{2, 500, 600}}; //must confirm the number of "columns"
//
//    for(int row=0; row<3; row++){
//        for(int col = 0; col<3; col++){
//            cout << my2DArray[row][col];
//            if(col < 2)
//                cout << ", ";
//            else
//                cout << endl;
//        }
//    }

//    //Arrays and pointers demo
//    int a[] = {1, 2, 3};
//    int *p;
//
//    p = a;
//    addTen(p, 3);
//    for(int row = 0; row <3; row++){
//        cout << a[row] << endl;
//    }

    int numArray[]= {1, 2, 3, 4, 5};
//    int sizeOfNumArray = sizeof(numArray); //sizeof() counts the bytes.
//    int sizeOfNumArray = sizeof(numArray) / sizeof(numArray[0]);
    int sizeOfNumArray = sizeof(numArray) / sizeof(int);
    cout << sizeOfNumArray;

    return 0;
}//end main

//method definition
void addTen(int *p, int ) {
    for(int row=0; row<3; row++){
        p[row] += 10;   //pointer is the samething as an array of the same data type
    }
}