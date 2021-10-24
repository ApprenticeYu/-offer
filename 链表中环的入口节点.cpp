#include<iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
};

ListNode* meeting_node(ListNode* head)
{
	if (head == nullptr)
	{
		return nullptr;
	}
	ListNode* slow = head->next;
	if (slow == nullptr)
	{
		return nullptr;
	}
	ListNode* fast = slow->next;
	while (fast != nullptr && slow != nullptr)
	{
		if (slow == fast)
		{
			return fast;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast != nullptr)
		{
			fast = fast->next;
		}
	}
	return nullptr;
}

ListNode* access_node(ListNode* head)
{
	if (head == nullptr)
	{
		return nullptr;
	}
	ListNode* meet = meeting_node(head);
	if (meet == nullptr)
	{
		return nullptr;
	}
	ListNode* node = meet;
	int count = 1;
	while (node->next != meet)
	{
		node = node->next;
		++count;
	}
	ListNode* node_1 = head;
	ListNode* node_2 = head;
	for (int i = 0; i < count; i++)
	{
		node_1 = node_1->next;
	}
	while (node_1 != node_2)
	{
		node_1 = node_1->next;
		node_2 = node_2->next;
	}
	return node_1;

}