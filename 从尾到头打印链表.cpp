#include<iostream>
#include<stack>

using namespace std;

struct ListNode
{
	int m_value;
	ListNode* next;
};

void print_node_reverse(ListNode* head)
{
	stack<ListNode*>node;
	if (head != nullptr)
	{
		ListNode* Node = head;
		while (Node != nullptr)
		{
			node.push(Node);
			Node = Node->next;
		}
		while (!node.empty())
		{
			Node = node.top();
			cout << Node->m_value << endl;
			node.pop();

		}
	}
}

void print_node_reverse_2(ListNode* head)
{
	if (head != nullptr)
	{
		if (head->next != nullptr)
		{
			print_node_reverse_2(head->next);
		}
		cout << head->m_value << endl;

	}

}