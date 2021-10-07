#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* parent;
};

BinaryTreeNode* nextnode(BinaryTreeNode* Node)
{
	if (Node == nullptr)
	{
		return nullptr;
	}
	BinaryTreeNode* next = nullptr;
	if (Node->right != nullptr)
	{
		BinaryTreeNode* right = Node->right;
		while (right->left != nullptr)
		{
			right = right->left;
		}
		next = right;
	}
	else if (Node->parent != nullptr)
	{
		BinaryTreeNode* current = Node;
		BinaryTreeNode* parent = Node->parent;
		while (parent != nullptr && current == parent->right)
		{
			current = parent;
			parent = parent->parent;
		}
		next = parent;
	}
	return next;

}