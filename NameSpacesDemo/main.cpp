#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

namespace NS1{int square(int num);}
namespace NS2{int square(int num);}

int main() {
    int answer = 0;
    //example of single use of NS1 square method implementation
    {
        using namespace NS1;    //use the new namespace within these braces
        answer = square(3);
        cout << "NS1 answer is: " << answer << endl;
    }

    {
        using namespace NS2;    //use the new namespace within these braces
        answer = square(3);
        cout << "NS2 answer is: " << answer << endl;
    }

    return 0;
} //end main

namespace NS1 {
    int square(int num){
        return num*num;
    }
}

namespace NS2 {
    int square(int num){
        return num*num + 42;
    }
}