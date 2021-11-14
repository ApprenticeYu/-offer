#include<iostream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

void convert_list(TreeNode* root, TreeNode** last_node)
{
	if (!root)
	{
		return;
	}
	TreeNode* current = root;
	if (current->left)
	{
		convert_list(current->left, last_node);
	}
	current->left = *last_node;
	if (*last_node != nullptr)
	{
		(*last_node)->right = current;
	}
	*last_node = current;
	if (current->right)
	{
		convert_list(current->right, last_node);
	}

}

TreeNode* binary_list(TreeNode* root)
{
	TreeNode* last_node = nullptr;
	convert_list(root, &last_node);
	TreeNode* first = last_node;
	while (first && first->left)
	{
		first = first->left;
	}
	return first;
}