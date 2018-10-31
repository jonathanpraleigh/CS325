#ifndef HW3_HPP
#define HW3_HPP

#include <iostream>
#include <fstream>
#include <vector>

int size, value, tempNum, index, converted;
std::string temp, convertToInts, convertToValue;


std::ifstream inputFile;
std::ofstream outputFile;

//int * result;
//int * amounts;
//int * denominations;

std::vector<int>tempVect;

void makingChange(int[], int, int, int *, int *);


#endif

