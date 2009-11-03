#ifndef _INTARRAY_H
#define _INTARRAY_H

class IntArray {
  private:
    int a;
    int b;
    int* num;
  public:
    IntArray(int start, int finish);
    IntArray(int finish = 9);
    int low();
    int high();
    int& operator[](int i);
};

#endif
