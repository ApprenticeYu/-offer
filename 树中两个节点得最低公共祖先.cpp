#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct TreeNode
{
	int value;
	vector<TreeNode*> children;
};

bool get_path(TreeNode* root, TreeNode* node, list<TreeNode*> path)
{
	if (root == node)
	{
		return true;
	}
	path.push_back(root);
	bool found = false;
	vector<TreeNode*>::iterator i = root->children.begin();
	while (!found && i < root->children.end())
	{
		found = get_path(*i, node, path);
		i++;
	}
	if (!found)
	{
		path.pop_back();
	}
	return found;
}

TreeNode* get_last(const list<TreeNode*>& path1, const list<TreeNode*>& path2)
{
	list<TreeNode*>::const_iterator p1 = path1.begin();
	list<TreeNode*>::const_iterator p2 = path2.begin();
	TreeNode* last = nullptr;
	while (p1 != path1.end() && p2 != path2.end())
	{
		if (*p1 == *p2)
		{
			last = *p1;
		}
		p1++;
		p2++;
	}
	return last;
}

TreeNode* get_last_core(TreeNode* node1, TreeNode* node2, TreeNode* root)
{
	if (node1 == nullptr || node2 == nullptr || root == nullptr)
	{
		return nullptr;
	}
	list<TreeNode*> path1;
	list<TreeNode*> path2;

	get_path(root, node1, path1);
	get_path(root, node2, path2);

	return get_last(path1, path2);
}