#include<iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
};

void delete_duplicate(ListNode** head)
{
	if (head == nullptr || *head == nullptr)
	{
		return;
	}
	ListNode* pre_node = nullptr;
	ListNode* Node = *head;
	while (Node)
	{
		ListNode* p_next = Node->next;
		bool need_delete = false;
		if (p_next != nullptr && p_next->value == Node->value)
		{
			need_delete = true;
		}
		if (!need_delete)
		{
			pre_node = Node;
			Node = Node->next;
		}
		else
		{
			ListNode* p_tobedelete = Node;
			int value = p_tobedelete->value;
			while (p_tobedelete != nullptr && p_tobedelete->value == value)
			{
				p_next = p_tobedelete->next;
				delete p_tobedelete;
				p_tobedelete = nullptr;
				p_tobedelete = p_next;
			}
			if (pre_node == nullptr)
			{
				*head = p_next;
			}
			else
			{
				Node->next = p_next;
			}
			Node = p_next;
		}
	}
}