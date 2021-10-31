#include<iostream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

bool is_symmetrical_core(TreeNode* root1, TreeNode* root2)
{
	if (root1 == nullptr && root2 == nullptr)
	{
		return true;
	}
	if (root1 == nullptr || root2 == nullptr)
	{
		return false;
	}
	if (root1->value != root2->value)
	{
		return false;
	}
	return is_symmetrical_core(root1->left, root2->right) && is_symmetrical_core(root1->right, root2->left);
}

bool is_symmetrical(TreeNode* root)
{
	return is_symmetrical_core(root, root);
}