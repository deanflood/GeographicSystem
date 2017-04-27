#pragma once
#include "City.h"
#include "TreeNode.h"
#include <algorithm>    // std::max

using namespace std;
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
	void nearByCities(pair<string, string>, int);

private:
	TreeNode * root;
	void add(TreeNode*, TreeNode*);
	TreeNode * deleteNode(TreeNode *&, string);
	bool deleteNode(TreeNode *, pair<string, string>);
	int height(TreeNode*);
	void printInOrder(TreeNode *);
	bool searchTree(TreeNode*, string);
	bool searchTree(TreeNode *, pair<string, string>);
	TreeNode * findMin(TreeNode *);
	TreeNode * findMax(TreeNode *);
	void nearByCities(TreeNode *, pair<string, string>, int);
	double calculateDistance(pair<string, string>, pair<string, string>);
};

