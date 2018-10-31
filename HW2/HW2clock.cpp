/********************************************************************************************
** Program name: StoogeSort - Assignment 2
** Author: Jon Raleigh
** Date: 1/21/18
** Description: Sorts an array in an inefficient way.
*******************************************************************************************/
#include "HW2.hpp"
#include <fstream>
#include <cmath>
#include <iostream>


int main()
{
	int integers;

	std::cout << "Enter the number of integers for this test." << std::endl;
	std::cin >> integers;

	int *array = new int[integers];

	for (int count = 0; count < integers; count++)
	{
		numbertoadd = rand() % 10000 + 1;
		array[count] = numbertoadd;
	}

	size = integers;
	first = 0;
	last = size - 1;


	long double duration;
	clock_t t;

	t = clock();

	StoogeSort(array, 0, size-1);

	duration = (clock() - t) / (long double)CLOCKS_PER_SEC;
	std::cout << "Seconds: " << duration << '\n';

	std::cout << "Press any key to exit.";
	std::cin.ignore();
	std::cin.get();

	delete[] array;

	return 0;
}

void StoogeSort(int *arr, int min, int max)
{

	if (min + 1 > max)
	{
		return;
	}

	if (arr[min] > arr[max])
	{
		std::swap(arr[min], arr[max]);
	}

	if (max - min + 1 > 2)
	{
		mid = (max - min + 1)/3;
		StoogeSort(arr, min, max - mid);
		StoogeSort(arr, min + mid, max);
		StoogeSort(arr, min, max - mid);
	}
}
