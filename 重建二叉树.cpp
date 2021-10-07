#include<iostream>
using namespace std;

struct TreeNode
{
	int m_value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
	{
		return nullptr;
	}
	return construct_core(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

TreeNode* construct_core(int* preorder_begin, int* preorder_end, int* inorder_begin, int* inorder_end)
{
	int value = preorder_begin[0];
	TreeNode* root = new TreeNode();
	root->m_value = value;
	root->left = root->right = nullptr;
	if (preorder_begin == preorder_end)
	{
		if (inorder_begin == inorder_end && *preorder_begin == *inorder_begin)
		{
			return root;
		}
		else
		{
			throw exception("Invalid input.");
		}
	}
	int* left_inorder_end = inorder_begin;
	if (left_inorder_end <= inorder_end && *left_inorder_end != value)
	{
		left_inorder_end++;
	}
	int length = left_inorder_end - inorder_begin;
	int* left_preorder_end = preorder_begin + length;
	if (length > 0)
	{
		root->left = construct_core(preorder_begin + 1, left_preorder_end, inorder_begin, left_inorder_end - 1);
	}
	if (length < preorder_end - preorder_begin)
	{
		root->right = construct_core(left_preorder_end + 1, preorder_end, left_inorder_end + 1, inorder_end);
	}
	return root;
}