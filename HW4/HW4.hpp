#ifndef HW4_HPP
#define HW4_HPP
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

int vCounter, setNumber;

std::ifstream inputFile;

struct classes
{
	int classID;
	int startTime;
	int finishTime;
};

std::vector<std::vector<classes>> vectorOfVectors;

bool sortByFinishDescending(const classes &, const classes &);
void vectorSort(std::vector<classes>*);
std::vector<std::vector<classes>> parseText();
std::vector<classes> greedyActivitySelectorReversed(std::vector<classes> set, int);
void outputToConsole(std::vector<classes>, int);

#endif

