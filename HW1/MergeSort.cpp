/********************************************************************************************
** Program name: MergeSort - Assignment 1
** Author: Jon Raleigh
** Date: 1/14/18
** Description: Reads from file, performs merge sort algorithm, writes to file.
*******************************************************************************************/

//includes here
#include "MergeSort.hpp"
#include <vector>

int main()
{
	inputFile.open("data.txt");

	while (inputFile >> number)
	{
		vect.push_back(number);
	}

	inputFile.close();

	size = vect.size();
	first = vect[0];
	last = vect[size - 1];
	
	MergeSort(vect, first, last);

	outputFile.open("merge.out");

	for (int count = 0; count < vect.size(); count++)
	{
		outputFile << vect[count];
	}

	outputFile.close();

	return 0;
}

void MergeSort(std::vector<int> ms_v, int a, int b)
{
	if (a < b) {
		index = (a + b) / 2;
		MergeSort(ms_v, a, index);
		MergeSort(ms_v, index + 1, b);
		Merge(ms_v, a, index, b);
	}
}

void Merge(std::vector <int> m_v, int c, int d, int e)
{
	i = d - c + 1;
	j = e - d;

// Copy to left and right vectors
	for (f = 0; f < i; f++)
		left[f] = m_v[c + f];
	for (g = 0; g < j; g++)
		left[g] = m_v[d + 1 + g];

// Merge sorting the left and right vectors back into vector
	f = 0; 
	g = 0; 
	h = c; 
	while (f < i && g < j)
	{
		if (left[f] <= right[g])
		{
			m_v[h] = left[f];
			f++;
		}
		else
		{
			m_v[h] = right[g];
			g++;
		}
		h++;
	}

// Copy what is left of left vector
	while (f < i)
	{
		m_v[h] = left[f];
		f++;
		h++;
	}

//copy what is left of right vector
	while (g < j)
	{
		m_v[h] = right[g];
		g++;
		h++;
	}
}