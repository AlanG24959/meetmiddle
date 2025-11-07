#include <iostream>
#include "src/middle.hpp"
using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    Array data;
    if (!loadDataFromFile(filename, data)) {
        cout << "Error: Could not open file '" << filename << "'." << endl;
        return 1;
    }

    double median = findMedian(data);
    cout << "\nThe median of the dataset is " << median << endl;

    return 0;
}
