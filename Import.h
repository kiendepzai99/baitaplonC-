#ifndef IMPORT_H
#define IMPORT_H
#include <vector>
#include <sstream>
using namespace std;
class Import{
public:
     static int numberLine(); // lấy ra số dòng trong file csv
     static vector<string> split (const string &s, char delim) ; // tách theo chuỗi theo dấu

};
#endif // IMPORT_H
