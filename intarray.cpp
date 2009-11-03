#include "intarray.h"	
#include <fstream>

using namespace std;

extern ofstream csis;

IntArray::IntArray (int start, int finish) {
  a = start;
  b = finish;
  num = new int[b-a];
}

IntArray::IntArray (int finish) {
  a = 0;
  b = finish;
  num = new int[b];
}

int IntArray::low() {
  return a;
}

int IntArray::high() {
  return b;
}

int& IntArray::operator[](int i) {
  return num[i+a];
}

