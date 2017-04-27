#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

void BinarySearchTree::add(City city)
{
	if (!searchTree(root, city.coordinates)) {
		TreeNode * toAdd = new TreeNode(city);
		if (root == nullptr) {
			root = toAdd;
		}
		else {
			add(toAdd, root);
		}
	}
}

void BinarySearchTree::deleteNode(string cityName)
{
	deleteNode(root, cityName);
	int i = 0;
}

void BinarySearchTree::deleteNode(pair<string, string> coordinates)
{
	deleteNode(root, coordinates);
}

bool BinarySearchTree::searchTree(string cityName)
{
	return searchTree(root, cityName);
}

bool BinarySearchTree::searchTree(pair<string, string> coordinates)
{
	return searchTree(root, coordinates);
}

int BinarySearchTree::height()
{
	return height(root);
}

void BinarySearchTree::printInOrder()
{
	if (root != nullptr) {
		printInOrder(root);
	}
}

void BinarySearchTree::nearByCities(pair<string, string> coordinates, int distance)
{
	nearByCities(root, coordinates, distance);
}

void BinarySearchTree::add(TreeNode * toAdd, TreeNode * addHere)
{
	if (toAdd->data < addHere->data) {
		if (addHere->leftPtr == nullptr) {
			addHere->leftPtr = toAdd;
		}
		else {
			add(toAdd, addHere->leftPtr);
		}
	}
	else if (toAdd->data > addHere->data) {
		if (addHere->rightPtr == nullptr) {
			addHere->rightPtr = toAdd;
		}
		else {
			add(toAdd, addHere->rightPtr);
		}
	}
}

TreeNode * BinarySearchTree::deleteNode(TreeNode *& node, string cityName)
{
		if (node != nullptr) {
		if (cityName.compare(node->data.name) < 0) {
			node->leftPtr = deleteNode(node->leftPtr, cityName);
		}
		else if (cityName.compare(node->data.name) > 0) {
			node->rightPtr = deleteNode(node->rightPtr, cityName);
		}
		else {
			if (node->leftPtr == nullptr && node->rightPtr == nullptr) {
				delete node;
				node = nullptr;
			}
			else if (node->leftPtr == nullptr) {
				TreeNode * temp = node;
				node = node->rightPtr;
				delete temp;
			}
			else if (node->rightPtr == nullptr) {
				TreeNode * temp = node;
				node = node->leftPtr;
				delete temp;
			}
			else {
				TreeNode * temp = findMin(node->rightPtr);
				node->data = temp->data;
				node->rightPtr = deleteNode(node->rightPtr, temp->data.name);
			}
		}
	}
	return node;
}

bool BinarySearchTree::deleteNode(TreeNode * node, pair<string, string> coordinates)
{
	if (node == nullptr) {
		return false;
	}
	else if (node->data.coordinates.first == coordinates.first && node->data.coordinates.second == coordinates.second) {
		deleteNode(node->data.name);
	}
	else {
		return deleteNode(node->leftPtr, coordinates) || deleteNode(node->rightPtr, coordinates);
	}
}

int BinarySearchTree::height(TreeNode * node)
{

	if (node == nullptr) {
		return -1;
	}
	else {
		return 1 + max(height(node->leftPtr), height(node->rightPtr));
	}
}

void BinarySearchTree::printInOrder(TreeNode * node)
{
	if (node != nullptr) {
		printInOrder(node->leftPtr);
		cout << node->data;
		printInOrder(node->rightPtr);
	}
}

bool BinarySearchTree::searchTree(TreeNode * node, string cityName)
{
	if (node == nullptr) {
		return false;
	}
	else if (node->data.name.compare(cityName) == 0) {
		return true;
	}
	else if (node->data.name.compare(cityName) < 0) {
		searchTree(node->rightPtr, cityName);
	}
	else if (node->data.name.compare(cityName) > 0) {
		searchTree(node->leftPtr, cityName);
	}
}

bool BinarySearchTree::searchTree(TreeNode * node, pair<string, string> coordinates)
{
	if (node == nullptr) {
		return false;
	}
	else if (node->data.coordinates.first == coordinates.first && node->data.coordinates.second == coordinates.second) {
		return true;
	}
	else {
		return searchTree(node->leftPtr, coordinates) || searchTree(node->rightPtr, coordinates);
	}
}

TreeNode * BinarySearchTree::findMin(TreeNode * node)
{
	while (node -> leftPtr != nullptr){
		node = node->leftPtr;
	}
	return node;
}

TreeNode * BinarySearchTree::findMax(TreeNode * node)
{
	while (node->rightPtr != nullptr) {
		node = node->rightPtr;
	}
	return node;
}

void BinarySearchTree::nearByCities(TreeNode * node, pair<string, string> coordinates, int distance)
{
	if (node != nullptr) {
		if (calculateDistance(coordinates, node->data.coordinates) < distance) {
			cout << node->data << "Distance From specified point: " << calculateDistance(coordinates, node->data.coordinates) << " KM" <<  endl;
		}
		nearByCities(node->leftPtr, coordinates, distance);
		nearByCities(node->rightPtr, coordinates, distance);
	}
}

/***************************************************************************************

*    Title: Calculate the distance between two coordinates by latitude and longitude
*    Author: Shields, W
*    Date: Dec 13 '08
*    Code version: NA
*    Availability: http://stackoverflow.com/a/365853/5440987

***************************************************************************************/
double BinarySearchTree::calculateDistance(pair<string, string> c1, pair<string, string> c2)
{
	const double DEG_TO_RAD = (3.14159 / 180);
	const int EARTH_RADIUS = 6367;

	double latitude1 = stod(c1.first);
	double longitude1 = stod(c1.second);
	double latitude2 = stod(c2.first);
	double longitude2 = stod(c2.second);

	double latDiff = (latitude2 - latitude1) * DEG_TO_RAD;
	double longDiff = (longitude2 - longitude1) * DEG_TO_RAD;


	double a = pow(sin(latDiff / 2.0), 2) + cos(latitude1*DEG_TO_RAD) * cos(latitude2* DEG_TO_RAD) * pow(sin(longDiff / 2.0), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double d = EARTH_RADIUS * c;

	return d;
}
