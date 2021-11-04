#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main() {
    string *cl = new string[2];
    cl[0]="inet";
    cl[1]="prog";
    Student st1("Test Tester", 2, cl);

    cout << st1;

    return 0;
}
