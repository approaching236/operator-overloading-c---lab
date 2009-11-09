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

IntArray::~IntArray()
{
    delete[] num;
    delete[] name;
}

IntArray::IntArray(IntArray &ia){
  num = new int[ia.high()-ia.low()];
  for (int i = a; i <= b; i++) {
    num[i] = ia[i];
  }
  a = ia.a;
  b = ia.b;
  name = new char[sizeof(ia.name)/4];
  for (int k = 0; k < (sizeof(ia.name)/4); k++) {
    name[k] = ia.name[k];
  }
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

char* IntArray::getName() {
  return name;
}

int& IntArray::operator[](int i) {
  return num[i-a];
}

void IntArray::setName(char *n) {
  name = n;
}

ostream& operator<< (ostream& os, IntArray& ia) {
  os << ia.getName() << ": ";
	for (int i = ia.low(); i <= ia.high(); i++) {
		os << ia[i] << " ";
	}
	return os;
}

int IntArray::length() {
	return (b - a);
}

IntArray& IntArray::operator=(IntArray& ia) {
	if (ia.length() == ia.length()) {
		for (int i = 0; i <= length(); i++) {
			num[i] = ia[ia.low()+i];
		}
		return *this;
	}
	cout << "different sizes";
	return *this;
}

// if intArrays have the same # of elements and those elements are equal
bool IntArray::operator==(IntArray ia) {
  if (length() == ia.length()) {
    for (int i = 0; i < ia.length(); i++) {
      if (num[a+i-1] != ia[ia.low()+i]) return false;
    }
    return true;
  } else return false;
}

bool IntArray::operator!=(IntArray ia) {
  if (length() == ia.length()) {
    for (int i = 0; i < ia.length(); i++) {
      if (num[a+i-1] != ia[ia.low()+i]) return true;
    }
    return false;
  } else return true;
}

IntArray& IntArray::operator+(IntArray ia) {
	IntArray sum(length());
	if (length() == ia.length()) {
		for (int i = 0; i <= length(); i++) {
			sum[i] = num[i] + ia[ia.low()+i];
		}
	}
	return sum;
}

bool IntArray::operator+=(IntArray ia) {
//  cout << *this << endl;
	if (length() == ia.length()) {
		for (int i = 0; i <= length(); i++) {
		  cout << i << " " << num[i] << endl;
			num[i] += ia[ia.low()+i];
		}
		return true;
	}
	cout << "totally simulating a halt" << endl;
	return false;
}

