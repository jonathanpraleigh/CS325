/********************************************************************************************
** Program name: StoogeSort - Assignment 2
** Author: Jon Raleigh
** Date: 1/21/18
** Description: 
*******************************************************************************************/
#include "HW2.hpp"
#include <fstream>
#include <cmath>
#include <iostream>


int main()
{
	inputFile.open("data.txt");

	while (inputFile >> number)
	{
		vect.push_back(number);
	}

	inputFile.close();

	size = vect.size();

	int *array = new int[size];

	for (int count = 0; count < size; count++)
	{
		array[count] = vect[count];
	}

	//array test what's going wrong????

	std::cout << "Contents of array" << std::endl;
	for (int count = 0; count < size; count++)
	{
		std::cout << array[count] << " ";
	}
	std::cout << " " << std::endl;
	std::cout << "Size of array per variable: " << size << std::endl;
	std::cout << "Size of vector: " << vect.size() << std::endl;

	//array test what's going wrong????

	StoogeSort(array, 0, size-1);

	outputFile.open("stooge.out");

	for (int count = 0; count < size; count++)
	{
		outputFile << array[count];
	}

	outputFile.close();

	std::cout << "Contents of array" << std::endl;
	for (int count = 0; count < size; count++)
	{
		std::cout << array[count] << " ";
	}
	std::cout << " " << std::endl;

	delete[] array;

	return 0;
}

void StoogeSort(int *arr, int min, int max)
{
	//for (int count = 0; count < 24; count++)
	//{
	//	std::cout << arr[count] << " ";
	//}
	//std::cout << " " << std::endl;

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
