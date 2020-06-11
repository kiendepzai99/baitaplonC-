#include "Import.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int Import :: numberLine(){
    ifstream f;
    char c;
    int numchars, numlines;

    f.open("C:\\Users\\Giang\\Desktop\\ImportData.csv");

    numchars = 0;
    numlines = 0;
    f.get(c);
    while (f) {
        while (f && c != '\n') {
            numchars = numchars + 1;
            f.get(c);
        }
        numlines = numlines + 1;
        f.get(c);
    }
    return(numlines);
}
vector<string> Import ::split(const string &s, char delim){
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}



