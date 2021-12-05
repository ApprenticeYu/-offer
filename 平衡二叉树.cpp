#include<iostream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

bool Tree_depth(TreeNode* root, int* depth)
{
	if (root == nullptr)
	{
		*depth = 0;
		return true;
	}
	int left, right;
	if (Tree_depth(root->left, &left) && Tree_depth(root->right, &right))
	{
		int diff = left - right;
		if (diff >= -1 && diff <= 1)
		{
			*depth = 1 + (left > right) ? left : right;
			return true;
		}
	}
	return false;
}

bool is_balanced(TreeNode* root)
{
	int depth = 0;
	return Tree_depth(root, &depth);
}