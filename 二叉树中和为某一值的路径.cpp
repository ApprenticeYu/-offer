#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

void find_path(TreeNode* root, int target, vector<int>& s, int path_sum)
{
	path_sum += root->value;
	s.push_back(root->value);
	bool leaf = root->left == nullptr && root->right == nullptr;
	if (path_sum == target && leaf)
	{
		vector<int>::iterator iter = s.begin();
		for (; iter != s.end();iter++)
		{
			cout << *iter;
		}
		cout << endl;
	}
	else
	{
		if (root->left)
		{
			find_path(root->left, target, s, path_sum);
		}
		if (root->right)
		{
			find_path(root->right, target, s, path_sum);
		}
	}
	s.pop_back();
}

void path(TreeNode* root, int target)
{
	if (!root)
	{
		return;
	}
	vector<int> s;
	int path_sum = 0;
	find_path(root, target, s, path_sum);
}