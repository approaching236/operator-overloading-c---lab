#ifndef _INTARRAY_H
#define _INTARRAY_H

class IntArray {
  private:
    int a;
    int b;
    int* num;
    char *name;
  public:
    IntArray(int start, int finish);
    IntArray(int finish = 9);
    int low();
    int high();
    int& operator[](int i);
    void setName(char *name);
};

#endif
