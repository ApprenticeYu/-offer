#include <iostream>
#include<fstream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

void Serialize(TreeNode* root, ostream& stream)
{
	if (!root)
	{
		stream << "$,";
		return;
	}
	stream << root->value << ',';
	Serialize(root->left, stream);
	Serialize(root->right, stream);
}

void Deserialize(TreeNode** root, istream& stream)
{
	int number;
	if (ReadStream(stream, &number))
	{
		*root = new TreeNode();
		(*root)->value = number;
		(*root)->left = nullptr;
		(*root)->right = nullptr;

		Deserialize(&(*root)->left, stream);
		Deserialize(&(*root)->right, stream);
	}
}