/********************************************************************************************
** Program name: InsertSort - Assignment 1
** Author: Jon Raleigh
** Date: 1/14/18
** Description: Reads from file, performs insertion sort algorithm, writes to file.
*******************************************************************************************/
#include "InsertSort.hpp"
#include <algorithm>

int main()
{
	inputFile.open("data.txt");

	while (inputFile >> number)
	{
		vect.push_back(number);
	}

	inputFile.close();

	size = vect.size();

	InsertSort(vect);

	outputFile.open("insert.out");

	for (int count = 0; count < vect.size(); count++)
	{
		outputFile << vect[count];
	}

	outputFile.close();
	return 0;
}

void InsertSort(std::vector<int>vect) 
{
	index1 = 0;
	while (index1 < vect.size())
	{
		index2 = index1;
		while (index2 > 0 && vect[index2 - 1] > vect[index2])
		{
			std::swap (vect[index2], vect[index2 - 1]);
			index2--;
		}
		index1++;
	}

}