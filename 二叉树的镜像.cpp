#include<iostream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

void Mirror(TreeNode* root)
{
	if (!root)
	{
		return;
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		return;
	}
	TreeNode* node = root->left;
	root->left = root->right;
	root->right = node;
	if (root->left)
	{
		Mirror(root->left);
	}
	if (root->right)
	{
		Mirror(root->right);
	}
}