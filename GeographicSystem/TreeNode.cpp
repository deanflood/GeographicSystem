#include "TreeNode.h"

TreeNode::TreeNode(City data)
{
	TreeNode::data = data;
	leftPtr = nullptr;
	rightPtr = nullptr;
}

bool TreeNode::isLeaf()
{
	if (leftPtr == nullptr && rightPtr == nullptr) {
		return true;
	}
	return false;
}
