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

void BinarySearchTree::prettyPrint()
{
	prettyPrint(root);
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

TreeNode * BinarySearchTree::deleteNode(TreeNode * node, string cityName)
{
	//TODO
	if (node == nullptr) {
		cout << cityName << " not found!" << endl;
		return false;
	}
	else if (node->leftPtr != nullptr && node->leftPtr->data.name.compare(cityName) == 0) {
		if (node->leftPtr->isLeaf()) {
			delete node->leftPtr;
			node->leftPtr = nullptr;
		}
		return false;
	}
	else if (node->rightPtr != nullptr && node->rightPtr->data.name.compare(cityName) == 0) {
		if (node->rightPtr->isLeaf()) {
			delete node->rightPtr;
			node->rightPtr = nullptr;
		}
		return false;
	}

	else if (node->data.name.compare(cityName) < 0) {
		deleteNode(node->rightPtr, cityName);
	}
	else if (node->data.name.compare(cityName) > 0) {
		deleteNode(node->leftPtr, cityName);
	}
}

int BinarySearchTree::height(TreeNode * node)
{

	if (node == nullptr) {
		return -1;
	}
	else if (node->isLeaf()) {
		return 1;
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
		cout << cityName << " not found!" << endl;
		return false;
	}
	else if (node->data.name.compare(cityName) == 0) {
		cout << node->data;
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

void BinarySearchTree::prettyPrint(TreeNode * node, int indent)
{
	if (node != nullptr) {
		if (node->rightPtr) {
			prettyPrint(node->rightPtr, indent + 4);
		}
		if (indent) {
			cout << setw(indent) << ' ';
		}
		if (node->rightPtr) cout << " /\n" << setw(indent) << ' ';
		cout << node->data << "\n ";
		if (node->leftPtr) {
			cout << setw(indent) << ' ' << " \\\n";
			prettyPrint(node->leftPtr, indent + 4);
		}
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

//http://stackoverflow.com/questions/365826/calculate-distance-between-2-gps-coordinates
double BinarySearchTree::calculateDistance(pair<string, string> c1, pair<string, string> c2)
{
	const double degreeToRadius = (3.13159 / 180);
	const int earthRadius = 6367;

	double Latitude1 = stod(c1.first);
	double Longitude1 = stod(c1.second);
	double Latitude2 = stod(c2.first);
	double Longitude2 = stod(c2.second);

	double latDiff = (Latitude2 - Latitude1) * degreeToRadius;
	double longDiff = (Longitude2 - Longitude1) * degreeToRadius;


	double a = pow(sin(latDiff / 2.0), 2) + cos(Latitude1*degreeToRadius) * cos(Latitude2* degreeToRadius) * pow(sin(longDiff / 2.0), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double d = earthRadius * c;

	return d;
}
