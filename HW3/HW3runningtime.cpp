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
	int integers;
	int denomAmt;

	std::string temp;
	std::cout << "Enter the number of denominations for this test." << std::endl;
	std::getline(std::cin, temp);
	integers = std::stoi(temp);


	int *denominations = new int[integers];

	for (int count = 0; count < integers; count++)
	{	
		denomAmt = 1;
		denominations[count] = denomAmt;
		denomAmt++;
	}

	std::cout << "Enter the value to make change for." << std::endl;
	std::cin >> value;


	int * result = new int[value+1];
	int * amounts = new int[value+1];

//write array and value to output file. 

	long double duration;
	clock_t t;

	t = clock();

	makingChange(denominations, integers, value, result, amounts); //passes array and value to function.
			
	duration = (clock() - t) / (long double)CLOCKS_PER_SEC;
	std::cout << "Seconds: " << duration << '\n';

	std::cout << "Press any key to exit.";
	std::cin.ignore();
	std::cin.get();

	delete [] result;
	delete [] amounts;
	delete [] denominations;
			
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