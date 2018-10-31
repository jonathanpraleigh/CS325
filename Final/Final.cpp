//TSP Group 43
//Anthony Clemente
//Peter Yetti
//Jonathan Paul Raleigh II

#include <fstream>
#include <vector>
#include <iostream>
#include <math.h>
#include <limits>

struct City {

	int id;
	bool visited;
	int x;
	int y;

	City(int id, bool visited, int x, int y) {
		this->id = id;
		this->visited = visited;
		this->x = x;
		this->y = y;
	}
};

std::vector<City*> nearestNeighbor(int* nearestNeighbors, int &recentShortestTour, int &tourDistOut, int start, std::vector<City*> &cities);

int main(int argc, char** argv)
{
	std::string fileName = argv[1];
	std::ifstream input_file;

	input_file.open(argv[1]);
	std::vector<City*> cities;
	int currId;
	int currX;
	int currY;
	while (input_file >> currId && input_file >> currX && input_file >> currY) {
		cities.push_back(new City(currId, false, currX, currY));
	}

	input_file.close();

	int* nearestNeighbors = new int[cities.size()];
	for (int i = 0; i < cities.size(); i++) {
		nearestNeighbors[i] = -1;
	}

	for (int i = 0; i < cities.size(); i++) {
		int minDist = std::numeric_limits<int>::max();
		int cityID;
		for (int j = 0; j < cities.size(); j++) {
			int currentDist = (int)round(sqrt(pow(cities[i]->x - cities[j]->x, 2) + pow(cities[i]->y - cities[j]->y, 2)));
			if (currentDist < minDist && i != j) {
				minDist = currentDist;
				cityID = j;
			}
		}
		nearestNeighbors[i] = cityID;
	}

	for (int i = 0; i < cities.size(); i++) {
		std::cout << nearestNeighbors[i] << std::endl;
	}

	std::vector<City*> shortestTour;
	int shortestTourDist = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < cities.size(); i++) {
		int currTourDist;
		std::cout << "Evaluating starting point city: " << i << std::endl;
		std::vector<City*> currTour = nearestNeighbor(nearestNeighbors, shortestTourDist, currTourDist, i, cities);
		for (auto city : cities) {
			city->visited = false;
		}
		if (currTourDist < shortestTourDist) {
			shortestTourDist = currTourDist;
			shortestTour = currTour;
		}	
	}

	std::ofstream output_file;

	output_file.open(fileName + ".tour");
	output_file << shortestTourDist << std::endl;
	for (auto city : shortestTour) {
		output_file << city->id << std::endl;
	}

	output_file.close();

	while (!cities.empty()) {
		delete cities.back();
		cities.pop_back();
	}

	delete [] nearestNeighbors;

	return 0;
}

std::vector<City*> nearestNeighbor(int* nearestNeighbors, int &recentShortestTour, int &tourDistOut, int start, std::vector<City*> &cities) {

	std::vector<City*> currTour;
	tourDistOut = 0;
	cities[start]->visited = true; //true
	currTour.push_back(cities[start]);
	int currVertex = start;
	while (currTour.size() != cities.size()) {
		int minDist = std::numeric_limits<int>::max();
		int minDistVertex = currVertex;
		if (cities[nearestNeighbors[currVertex]]->visited == false) {
			currTour.push_back(cities[nearestNeighbors[currVertex]]);
			cities[nearestNeighbors[currVertex]]->visited = true;
			tourDistOut += (int)round(sqrt(pow(cities[currVertex]->x - cities[nearestNeighbors[currVertex]]->x, 2) + pow(cities[currVertex]->y - cities[nearestNeighbors[currVertex]]->y, 2)));
			currVertex = nearestNeighbors[currVertex];
		}
		else {
			for (unsigned int i = 0; i < cities.size(); i++) {
				if (cities[i]->visited == false) {
					int currDist = (int)round(sqrt(pow(cities[currVertex]->x - cities[i]->x, 2) + pow(cities[currVertex]->y - cities[i]->y, 2)));
					if (currDist < minDist) {
						minDist = currDist;
						minDistVertex = i;
					}
				}
			}
			if (currTour.size() != cities.size())
				currVertex = minDistVertex;
			currTour.push_back(cities[currVertex]);
			cities[currVertex]->visited = true;
			tourDistOut += minDist;
		}
		if (tourDistOut > recentShortestTour) {
			return currTour;
		}


	}

	tourDistOut += (int)round(sqrt(pow(currTour[0]->x - currTour.back()->x, 2) + pow(currTour[0]->y - currTour.back()->y, 2)));

	return currTour;
}