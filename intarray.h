#ifndef _INTARRAY_H
#define _INTARRAY_H
#include <fstream>
#include <iomanip>

using namespace std;

class IntArray {
  private:
    int a;
    int b;
    int* num;
    char *name;
  public:
    IntArray(int start, int finish);
    IntArray(int finish = 10);
//    IntArray(const IntArray&);
    int low();
    int high();
    int& operator[](int i);
    friend ostream& operator<<(ostream& os, IntArray& ia);
    void setName(char *name);
  	int length();
  	IntArray& operator=(IntArray&);
  	bool operator==(IntArray);
  	bool operator!=(IntArray);
};

#endif
