#pragma once
#include "City.h"
#include "TreeNode.h"
#include <iomanip>
#include <algorithm>    // std::max

class BinarySearchTree
{
public:
	BinarySearchTree();
	void add(City);
	void deleteNode(string);
	void deleteNode(pair<string, string>);
	bool searchTree(string);
	bool searchTree(pair<string, string>);
	int height();
	void printInOrder();
	void prettyPrint();
private:
	TreeNode * root;
	void add(TreeNode*, TreeNode*);
	int height(TreeNode*);
	void printInOrder(TreeNode *);
	bool searchTree(TreeNode*, string);
	bool searchTree(TreeNode *, pair<string, string>);
	void prettyPrint(TreeNode *, int indent = 0);
};
