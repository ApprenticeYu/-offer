#include<iostream>
#include<deque>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

class Solution
{
public:
	void print_tree(TreeNode* root)
	{
		if (!root)
		{
			return;
		}
		deque<TreeNode*>d;
		d.push_back(root);
		while (d.size())
		{
			TreeNode* Node = d.front();
			d.pop_front();
			cout << Node->value;
			if (Node->left)
			{
				d.push_back(Node->left);
			}
			if (Node->right)
			{
				d.push_back(Node->right);
			}
		}
	}
};