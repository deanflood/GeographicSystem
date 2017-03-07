#pragma once
#include <iostream>
#include <string>
using namespace std;

class City
{
	friend class TreeNode;
	friend class BinarySearchTree;
public:
	City();
	City(string, int, double, pair<string, string>);
	friend ostream& operator<<(ostream& stream, City& city);
	bool operator<(City& city);
	bool operator>(City& city);
private:
	string name;
	int population;
	double averageTemperature;
	pair<string, string> coordinates;
};

