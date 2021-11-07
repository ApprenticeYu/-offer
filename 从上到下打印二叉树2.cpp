#include<iostream>
#include<queue>
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
	queue<TreeNode*> q;
	q.push(root);
	int to_print = 1;
	int next_level = 0;
	while (!q.empty())
	{
		TreeNode* node = q.front();
		cout << node->value;
		if (node->left)
		{
			q.push(node->left);
			++next_level;
		}
		if (node->right)
		{
			q.push(node->right);
			++next_level;
		}
		q.pop();
		--to_print;
		if (to_print == 0)
		{
			cout << endl;
			to_print = next_level;
			next_level = 0;
		}
	}
}