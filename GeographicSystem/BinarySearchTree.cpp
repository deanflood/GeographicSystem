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

void BinarySearchTree::prettyPrint()
{
	prettyPrint(root);
}

void BinarySearchTree::nearByCities(pair<string, string> coordinates, int distance)
{
	nearByCities(root, coordinates, distance);
}

bool BinarySearchTree::isRootNull()
{
	return (root == nullptr);
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
		cout << cityName << " not found!" << endl;
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
	const double degreeToRadius = (3.14159 / 180);
	const int earthRadius = 6367;

	double latitude1 = stod(c1.first);
	double longitude1 = stod(c1.second);
	double latitude2 = stod(c2.first);
	double longitude2 = stod(c2.second);

	double latDiff = (latitude2 - latitude1) * degreeToRadius;
	double longDiff = (longitude2 - longitude1) * degreeToRadius;


	double a = pow(sin(latDiff / 2.0), 2) + cos(latitude1*degreeToRadius) * cos(latitude2* degreeToRadius) * pow(sin(longDiff / 2.0), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double d = earthRadius * c;

	return d;
}
