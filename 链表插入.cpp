#include<iostream>
using namespace std;

struct ListNode
{
	int m_value;
	ListNode* next;

};

void add_to_tail(ListNode** head, int value)
{
	ListNode* Node = new ListNode();
	Node->m_value = value;
	Node->next = nullptr;
	if (*head == nullptr)
	{
		*head = Node;
	}
	else
	{
		ListNode* node = *head;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		node->next = Node;
	}

}

void removenode(ListNode** head, int value)
{
	if (head == nullptr || *head == nullptr)
	{
		return;
	}
	ListNode* tobedeleted = nullptr;
	if ((*head)->m_value == value)
	{
		tobedeleted = *head;
		*head = (*head)->next;
	}
	else
	{
		ListNode* Node = *head;
		while(Node->next != nullptr && Node->next->m_value != value)
		{
			Node = Node->next;
		}
		if (Node->next != nullptr && Node->next->m_value == value)
		{
			tobedeleted = Node->next;
			Node->next = Node->next->next;
		}
	}
	if (tobedeleted != nullptr)
	{
		delete tobedeleted;
		tobedeleted = nullptr;
	}
}