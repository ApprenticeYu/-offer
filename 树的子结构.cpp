#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

bool Tree_sub_core(TreeNode* root1, TreeNode* root2)
{
	if (root2 == nullptr)
	{
		return true;
	}
	if (root1 == nullptr)
	{
		return false;
	}
	if (!Equal(root1->val, root2->val))
	{
		return false;
	}
	return Tree_sub_core(root1->left, root2->left) && Tree_sub_core(root1->right, root2->right);

}

bool Tree_sub(TreeNode* root1, TreeNode* root2)
{
	bool result = false;
	if (root1 != nullptr && root2 != nullptr)
	{
		if (Equal(root1->val, root2->val))
		{
			result = Tree_sub_core(root1, root2);
		}
		if (!result)
		{
			result = Tree_sub(root1->left, root2);
		}
		if (!result)
		{
			result = Tree_sub(root1->right, root2);
		}
	}
	return result;
}