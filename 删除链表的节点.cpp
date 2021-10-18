#include<iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
};

void delete_listnode(ListNode** head, ListNode* p_tobedeleted)
{
	if (!head || !p_tobedeleted)
	{
		return;
	}
	if (p_tobedeleted->next != nullptr)
	{
		ListNode* next = p_tobedeleted->next;
		p_tobedeleted->value = next->value;
		p_tobedeleted->next = next->next;

		delete next;
		next = nullptr;
	}
	else if (*head == p_tobedeleted)
	{
		delete p_tobedeleted;
		*head = nullptr;
		p_tobedeleted = nullptr;
	}
	else
	{
		ListNode* Node = *head;
		while (Node->next != p_tobedeleted)
		{
			Node = Node->next;
		}
		Node->next = nullptr;
		delete p_tobedeleted;
		p_tobedeleted = nullptr;
	}
}