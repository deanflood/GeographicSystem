#pragma once
#include "City.h"
class TreeNode
{
	friend class BinarySearchTree;
public:
	TreeNode(City data);
	bool isLeaf();
private:
	TreeNode * leftPtr;
	TreeNode * rightPtr;
	City data;
};

