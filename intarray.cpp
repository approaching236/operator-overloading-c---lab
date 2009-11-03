#include "intarray.h"
#include <iostream>
#include <fstream>

using namespace std;

extern ofstream csis;

IntArray::IntArray (int start, int finish) {
  a = start;
  b = finish;
  num = new int[b-a];
  setName("");
}

IntArray::IntArray (int finish) {
  a = 0;
  b = finish;
  num = new int[b];
  setName("");
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

void IntArray::setName(char *n) {
  name = n;
}

ostream& operator<< (ostream& os, IntArray& ia) {
	for (int i = ia.low(); i <= ia.high(); i++) {
		os << ia[i] << " ";
	}
	return os;
}

