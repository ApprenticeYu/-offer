#include<iostream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* kth_node_core(TreeNode* root, unsigned int& k)
{
	TreeNode* target = nullptr;
	if (root->left != nullptr)
	{
		target = kth_node_core(root->left, k);
	}
	if (target == nullptr)
	{
		if (k == 1)
		{
			target = root;
		}
		--k;
	}
	if (target == nullptr && root->right != nullptr)
	{
		target = kth_node_core(root->right, k);
	}
	return target;
}

TreeNode* kth_node(TreeNode* root,unsigned int k)
{
	if (root == nullptr || k == 0)
	{
		return nullptr;
	}
	return kth_node_core(root, k);
}