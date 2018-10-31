/********************************************************************************************
** Program name: HW5 - Assignment 5
** Author: Jon Raleigh
** Date: 2/17/18
** Description: Determines if graph is bipartite and prints divided nodes.
*******************************************************************************************/
#include "HW5.hpp"

int main(int argc, char* argv[])
{
	buildRoster(argv[1]);
	success = workTheList();
	printTheResults(success);
	return 0;
}

/********************************************************************************************
** function name : buildRoster
** inputs: name of file argument from main.
** returns: none
** Description: creates vector of structs and vectors of pointers to other structs within 
**				them
*******************************************************************************************/

void buildRoster(std::string f)
{
	inputFile.open(f);
	
	inputFile >> counter;

	roster.reserve(20);

	for (int i = 0; i < counter; i++)
	{
		wrestler temp;
		temp.rivals.reserve(20);
		inputFile >> temp.name;
		roster.push_back(temp);
	}

	inputFile >> counter;

	for (int i = 1; i <= counter; i++)
	{
		inputFile >> one;
		inputFile >> two;

		for (int j = 0; j < roster.size(); j++)
		{
			if (one == roster[j].name)
				p_one = &roster[j];
			if (two == roster[j].name)
				p_two = &roster[j];
		}

		p_one->rivals.push_back(p_two);
		p_two->rivals.push_back(p_one);

	}
}

/********************************************************************************************
** function name : workTheList
** inputs: none
** returns: bool value that indicates successful determination if graph is bipartite
** Description: iterates through vector and passes unworked structs to assignStatus function.
*******************************************************************************************/

bool workTheList()
{
	for (int k = 0; k < roster.size(); k++)
	{
		if (roster[k].visited == false)
		{
			passed = assignStatus(&roster[k], 1);
			if (passed == false)
				return false;
		}
	}
	return true;
}

/********************************************************************************************
** function name : assignStatus
** inputs: pointer to struct and integer value referring to visited status
** returns: bool value that indicates successful assignment of status values.
** Description: assigns visited and babyface/heel status and returns true upon success or
**				false if the operation cannot be completed.
*******************************************************************************************/

bool assignStatus(wrestler* w, int newStatus)
{

	if (w->status == newStatus)
		return true;
	if (w->status == newStatus * -1)
		return false;

	w->visited = true;

	w->status = newStatus;

	if (newStatus == 1)
		babyfaces.push_back(w->name);
	else if (newStatus == -1)
		heels.push_back(w->name);

	for (int i = 0; i < w->rivals.size(); i++)
	{
		if (w->rivals.size() == 0) 
			return true;

		pass = assignStatus(w->rivals[i], newStatus * -1);
		if (pass == false)
		{
			return false;
		}	
	}
	return true;
}

/********************************************************************************************
** function name : workTheList
** inputs: bool value referring to successful assignment of statuses to nodes.
** returns: none
** Description: Upon failure, prints no. Upon success, prints lists of babyfaces and heels.
*******************************************************************************************/

void printTheResults(bool result)
{
	if (result == false)
	{
		std::cout << "\nNo" << std::endl;
		return;
	}
		
	std::cout << "\nYes\nBabyfaces : ";

	for (int i = 0; i < babyfaces.size(); i++)
	{
		std::cout << babyfaces[i] << " ";
	}

	std::cout << "\nHeels : ";

	for (int i = 0; i < heels.size(); i++)
	{
		std::cout << heels[i] << " ";
	}

	std::cout << "\n";
}
