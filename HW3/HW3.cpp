/********************************************************************************************
** Program name: Make Change - Assignment 3
** Author: Jon Raleigh
** Date: 1/28/18
** Description: Uses dynamic programming to make change using minimum number of units.
*******************************************************************************************/
#include "HW3.hpp"
#include <limits.h>
#include <string>
#include <iostream>
#include <sstream>

int main()
{

	//file input

	inputFile.open("amount.txt");

	outputFile.open("change.txt");

	while (!inputFile.eof())
	{

		if(!getline(inputFile, convertToInts)) break;
		getline(inputFile, convertToValue);

		std::stringstream ss(convertToInts);
		while(1)
		{
			int n;
			ss >> n;
			if (!ss)
				break;
			tempVect.push_back(n);
		}

		std::stringstream stream(convertToValue);
		stream >> value;

		size = tempVect.size();


		int * denominations = new int[size];

		for (int count = 0; count < size; count++)
		{
			denominations[count] = tempVect[count];
		}

		int * result = new int[value+1];
		int * amounts = new int[value+1];

//write array and value to output file. 
		for (int count = 0; count < size; count++)
		{
			outputFile << denominations[count] << " ";
		}

		outputFile << "\n";
		outputFile << value << "\n";
 

		makingChange(denominations, size, value, result, amounts); //passes array and value to function.
		
		index = value; 
		outputFile << "Numbers indicate array position. 3 0's mean 3 of the denomination at array[0]." << std::endl;
		while( index > 0)
		{
			outputFile << amounts[index] << " ";
			index = index - denominations[(amounts[index])];
		}

		outputFile << "\n";

		outputFile << result[value] << "\n\n";
	
		delete [] result;
		delete [] amounts;
		delete [] denominations;
		

		tempVect.clear();
	}

	inputFile.close();
	outputFile.close();

	return 0;
}

void makingChange(int denom[], int sz, int A, int *res, int *amt)
{
	res[0] = 0;
	int coin;

	for (int i = 1; i <= A; i++)
		res[i] = INT_MAX;

	for (int i =1; i <=A; i++)
	{
		int min = INT_MAX;
		for(int j = 0; j<sz; j++)
		{
			if (denom[j] <= i)
			{
				if (res[i - denom[j]] + 1 < min)
				{
					min = res[i - denom[j]] + 1;
					coin = j;
				}
			}
		}
		res[i] = min;
		amt[i] = coin;
	}

}