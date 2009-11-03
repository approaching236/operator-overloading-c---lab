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
  b = (finish - 1);
  num = new int[finish];
  setName("");
}

//IntArray::IntArray (const IntArray&) {
//  a = this.low();
//  b = this.high();
//  for (int i = a; i <= b; i++) {
//    num[i] = ia[i];
//  }
//}

int IntArray::low() {
  return a;
}

int IntArray::high() {
  return b;
}

int& IntArray::operator[](int i) {
  return num[i-a];
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

int IntArray::length() {
	return (b - a);
}

IntArray& IntArray::operator=(const IntArray& ia) {
	if (ia.length() == ia.length()) {
		for (int i = 0; i <= length(); i++) {
			num[i] = ia[ia.low()+i];
		}
		return *this;
	}
	cout << "different sizes";
	return *this;
}


