#include <iostream>
using namespace std;

class MyClass
{
public:
    void mod2DArray(int p[][3], int rowSize, int colSize)
    {
        for(int row=0; row< rowSize; row++)
        {
            for(int col = 0; col< colSize; col++ )
            {
                p[row][col] += 10;
            } //end inner for
        }//end outer for
    }// end method
}; //end class

int main() {
    //instantiate MyClass
    MyClass myClass = MyClass();
    int twoDnumArray[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rowSize = 3;
    int colSize = 3;

    cout << "2D array before modification" << endl;
    for(int row=0; row< rowSize; row++)
    {
        for(int col=0;col<colSize;col++)
        {
            cout << twoDnumArray[row][col];
        }
    }

    //call function to do modification
    myClass.mod2DArray(twoDnumArray, rowSize, colSize);

    cout << "\n2D array after modification" << endl;
    for(int row=0; row< rowSize; row++)
    {
        for(int col=0;col<colSize;col++)
        {
            cout << twoDnumArray[row][col];
        }
    }

    return 0;
} // end main
