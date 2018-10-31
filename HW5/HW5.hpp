#ifndef HW5_HPP
#define HW5_HPP
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <iostream>

int counter, location;
bool passed, pass, success;

std::string one, two;

std::ifstream inputFile;

struct wrestler
{
	std::string name;
	int status = 0;
	bool visited = false;
	std::vector<wrestler*>rivals;
};

wrestler* p_one;
wrestler* p_two;

std::vector<wrestler>roster;
std::vector<std::string>babyfaces;
std::vector<std::string>heels;

//functions
void buildRoster(std::string);
bool workTheList();
bool assignStatus(wrestler*, int);
void printTheResults(bool);

#endif

