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

