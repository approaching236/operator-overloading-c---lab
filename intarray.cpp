#include "intarray.h"
#include <iostream>
#include <fstream>

using namespace std;

extern ofstream csis;

IntArray::IntArray (int start, int finish) {
  if (start > finish) {
    cout << "simulating a halt, the following data simply prevents an error in the program, though is incorrect" << endl;
    a = finish;
    b = start;
  } else {
    a = start;
    b = finish;
  }
  num = new int[b-a];
  name = new char[1];
}

IntArray::IntArray (int finish) {
  a = 0;
  b = (finish - 1);
  num = new int[finish];
  name = new char[1];
}

//IntArray::~IntArray()
//{
//    delete[] num;
//    delete[] name;
//}

//IntArray::IntArray(IntArray &ia){
//  num = new int[ia.high()-ia.low()+1];
//  for (int i = 0; i <= (ia.high()-ia.low()); i++) {
//    num[i] = ia.num[i];
//  }
//  a = ia.a;
//  b = ia.b;
////  name=ia.name;
////  cout << sizeof(ia.name) << " " << ia.name[1] << endl;
////  name = new char[sizeof(ia.name)];
////  for (int k = 0; k < (sizeof(ia.name)/4); k++) {
////    name[k] = ia.name[k];
////  }
//  cout << "finished copy" << endl;
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
  if (i < a || i > b) {
    cout << "i: " << i << endl;
    cout << "out of bounds error. Simulating halt." << endl;
    return num[a];
  }
  return num[i-a];
}

void IntArray::setName(char *n) {
  name = n;
}

ostream& operator<< (ostream& os, IntArray& ia) {
	for (int i = ia.low(); i <= ia.high(); i++) {
		os << ia.name << "[" << i << "] = " << ia[i] << endl;
	}
	return os;
}

int IntArray::length() {
	return (b - a);
}

IntArray& IntArray::operator=(IntArray& ia) {
	if (length() == ia.length()) {
		for (int i = 0; i <= length(); i++) {
			num[i] = ia[ia.low()+i];
		}
		return *this;
	}
	cout << "different sizes. Simulating halt." << endl;
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
	IntArray sum(ia.length());
	if (length() == ia.length()) {
		for (int i = 0; i < length(); i++) {
			sum[i] = num[i] + ia[ia.low()+i];
		}
	}
	return sum;
}

bool IntArray::operator+=(IntArray ia) {
//  cout << *this << endl;
	if (length() == ia.length()) {
		for (int i = 0; i <= length(); i++) {
			num[i] += ia[ia.low()+i];
		}
		return true;
	}
	cout << "totally simulating a halt" << endl;
	return false;
}

