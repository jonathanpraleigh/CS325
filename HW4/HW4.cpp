/********************************************************************************************
** Program name: Last-to-Start Implementation - Assignment 4
** Author: Jon Raleigh
** Date: 2/4/18
** Description: Uses greedy algorithm to implement the last-to-start algorithm
*******************************************************************************************/
#include "HW4.hpp"

int main()
{
	vectorOfVectors = parseText();
	setNumber = 0;
	vCounter = vectorOfVectors.size();
	for (int i = 0; i < vCounter; i++)
	{
		setNumber++;
		std::vector<classes> vectToDisplay = greedyActivitySelectorReversed(vectorOfVectors[i], vectorOfVectors[i][0].startTime);
		outputToConsole(vectToDisplay, setNumber);
	}
	return 0;
}

std::vector<std::vector<classes>> parseText()
{
	inputFile.open("act.txt");
	std::vector<std::vector<classes>> outerHolder;
	int counter;

	while (true)
	{
		inputFile >> counter;
		if (inputFile.eof()) break;
		std::vector<classes> innerHolder;
		for (int i = 1; i <= counter; i++)
		{
			classes temp;
			inputFile >> temp.classID;
			inputFile >> temp.startTime;
			inputFile >> temp.finishTime;
			innerHolder.push_back(temp);
		}
		vectorSort(&innerHolder);
		outerHolder.push_back(innerHolder);
	}

	return outerHolder;
}

void vectorSort(std::vector<classes>* toSort)
{
	std::sort(toSort->begin(), toSort->end(), sortByFinishDescending);
}	

bool sortByFinishDescending(const classes &a, const classes &b)
{
	return a.finishTime > b.finishTime;
}



std::vector<classes> greedyActivitySelectorReversed(std::vector<classes> set, int sTime)
{
	std::vector<classes> finalSet;
	int maxIndex = set.size();
	finalSet.push_back(set[0]);
	int index = 0;
	for (int newIndex = 1; newIndex < maxIndex; newIndex++)
	{
		if (set[newIndex].finishTime <= set[index].startTime)
		{
			finalSet.push_back(set[newIndex]);
			index = newIndex;
		}
	}

	return finalSet;
}

void outputToConsole(std::vector<classes> toDisplay, int setN)
{
	std::cout << "\n" << "Set " << setN << "\n";
	std::cout << "Number of activities selected = " << toDisplay.size() << "\n";
	std::cout << "Activities: ";
	for (int i = toDisplay.size() -1; i >= 0; i--)
	{
		std::cout << toDisplay[i].classID << " ";
	}
	std::cout << "\n\n";
}
