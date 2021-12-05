#include<iostream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

int Tree_depth(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int left = Tree_depth(root->left);
	int right = Tree_depth(root->right);
	return 1 + (left > right) ? left : right;
}