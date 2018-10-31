/********************************************************************************************
** Program name: InsertSort Assignment 1
** Author: Jon Raleigh
** Date: 1/14/18
** Description: header file for InsertSort.cpp
*******************************************************************************************/

#ifndef INSERTSORT_HPP
#define INSERTSORT_HPP

#include <vector>
#include <fstream>

int index1, index2, number, size;

std::ifstream inputFile;
std::ofstream outputFile;

std::vector <int> vect;

void InsertSort(std::vector<int>);

#endif

