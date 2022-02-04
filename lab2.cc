/**
 *   @file: lab2.cc
 * @author: Josh Marusek
 *   @date: 2022-01-25
 *  @brief: Prints a sorted list of numbers from a file.
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "numlist.h"
using namespace std;

int main(int argc, char const *argv[]) {
    ifstream inputFile;
    ofstream outputFile;
    string fileName;

    NumList nums;
    int newNum;

    // get file name
    cout << "Enter the file name: ";
    cin >> fileName;
    cout << endl;

    // load nums from file
    inputFile.open(fileName.c_str());
    if (inputFile.fail()) {
        cout << "Failed to open file." << endl;
        exit(0);
    }
    nums.load_from_file(inputFile);
    inputFile.close();

    // sort nums and print result
    nums.b_sort();
    cout << "Sorted contents:" << endl;
    nums.see_all(cout);
    cout << endl;

    // get 3 more numbers and add them to the NumList
    cout << "Enter 3 numbers: ";
    for (size_t i = 0; i < 3; i++) {
        cin >> newNum;
        nums.insert(newNum);
    }

    // prepare the new file
    fileName = fileName.substr(0, fileName.find('.')) + "sorted" + fileName.substr(fileName.find('.'));  // add 'sorted' before first dot of file name
    outputFile.open(fileName);
    if (outputFile.fail()) {
        cout << "Failed to open file." << endl;
        exit(0);
    }

    // sort nums and save to new file
    nums.b_sort();
    nums.see_all(outputFile);
    outputFile.close();
}