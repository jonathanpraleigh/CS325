/********************************************************************************************
** Program name: MergeSort - Assignment 1
** Author: Jon Raleigh
** Date: 1/14/18
** Description: Header file for MergeSort.cpp
*******************************************************************************************/

#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>
#include <fstream>

int size, index, value, first, last, number;
int f, g, h, i, j;

std::ifstream inputFile;
std::ofstream outputFile;

std::vector <int> vect;
std::vector <int> numbers;
std::vector <int> left; 
std::vector <int> right;

void MergeSort(std::vector<int> v, int a, int b);
void Merge(std::vector<int>v, int a, int size, int b);

#endif
