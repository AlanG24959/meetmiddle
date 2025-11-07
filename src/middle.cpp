#include "middle.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Array::Array() : data(nullptr), size(0), capacity(0) {}

Array::~Array() {
   delete[] data;
}

void Array::resize(int newCap) {
   int* temp = new int[newCap];
   for (int i = 0; i < size; ++i)
      temp[i] = data[i];
   delete[] data;
   data = temp;
   capacity = newCap;
}

void Array::push_back(int value) {
   if (size == capacity) {
      int newCap = (capacity == 0) ? 2 : capacity * 2;
      resize(newCap);
   }
   data[size++] = value;
}

int Array::getSize() const {
   return size;
}

int Array::get(int index) const {
   return data[index];
}

bool loadDataFromFile(const string& filename, Array& arr) {
   ifstream file(filename);
   if (!file)
      return false;

   int value;
   char comma;

   while (file >> value) {
      arr.push_back(value);
      file >> comma;
   }
   return true;
}

double findMedian(const Array& arr) {
   int n = arr.getSize();
   if (n == 0)
      return 0;
   if (n % 2 == 1)
      return arr.get(n / 2);
   int mid1 = arr.get(n / 2 - 1);
   int mid2 = arr.get(n / 2);
   return (mid1 + mid2) / 2.0;
}
