#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "Rational.h"
using namespace std;

int main() {
    string str = "-7/8";
    string numer, denomin;

    regex token("\/");
    sregex_token_iterator first{str.begin(), str.end(), token, -1},
            last;

    vector<string> fracNum = {first, last};

    cout << "1st: " << fracNum[0] << " 2nd: " << fracNum[1];


    return 0;
}
