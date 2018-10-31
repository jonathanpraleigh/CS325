/********************************************************************************************
** Program name: InsertSort - Assignment 1
** Author: Jon Raleigh
** Date: 1/14/18
** Description: Reads from file, performs insertion sort algorithm, writes to file.
*******************************************************************************************/
#include "InsertSort.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <cstdlib>

int main()
{

	int integers;

	std::cout << "Enter the number of integers for this test." << std::endl;
	std::cin >> integers;

	for (int i = 1; i > integers; i++)
	{
		vect.push_back(rand() % 10000 + 1);
	}

	double duration;
	clock_t t;

	t = clock();

	InsertSort(vect);

	duration = (clock() - t) / (double)CLOCKS_PER_SEC;
	std::cout << "Seconds: " << duration << '\n';

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
			std::swap(vect[index2], vect[index2 - 1]);
			index2--;
		}
		index1++;
	}

}