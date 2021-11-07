#include<iostream>
#include<stack>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

void print_tree(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	stack<TreeNode*>s[2];
	int current = 0;
	int next = 1;
	s[current].push(root);
	while (!s[current].empty() || !s[next].empty())
	{
		TreeNode* Node = s[current].top();
		s[current].pop();
		cout << Node->value;
		if (current == 0)
		{
			if (Node->left)
			{
				s[next].push(Node->left);
			}
			if (Node->right)
			{
				s[next].push(Node->right);
			}
		}
		else
		{
			if (Node->right)
			{
				s[next].push(Node->right);
			}
			if (Node->left)
			{
				s[next].push(Node->left);
			}
		}
		if (s[current].empty())
		{
			cout << endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
}