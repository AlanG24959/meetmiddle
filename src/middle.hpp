#pragma once
#include <string>
using namespace std;

class Array {
private:
    int* data;
    int size;
    int capacity;
    void resize(int newCap);

public:
    Array();
    ~Array();
    void push_back(int value);
    int getSize() const;
    int get(int index) const;
};

bool loadDataFromFile(const string& filename, Array& arr);
double findMedian(const Array& arr);
