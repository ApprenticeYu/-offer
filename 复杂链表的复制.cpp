#include<iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
	ListNode* slide;
};

void Complicated_listnode(ListNode* head)
{
	ListNode* node = head;
	while (node)
	{
		ListNode* new_node = new ListNode();
		new_node->value = node->value;
		new_node->next = node->next;
		new_node->slide = nullptr;
		node->next = new_node;
		node = new_node->next;
	}
}

void slide_connect(ListNode* head)
{
	ListNode* node = head;
	while (node)
	{
		ListNode* new_node = node->next;
		if (node->slide)
		{
			new_node->slide = node->slide->next;
		}
		node = new_node->next;
	}
}

ListNode* reconnect(ListNode* head)
{
	ListNode* node = head;
	ListNode* new_node = nullptr;
	ListNode* new_head = nullptr;
	if (node)
	{
		new_head = new_node = node->next;
		node->next = new_node->next;
		node = node->next;
	}
	while (node)
	{
		new_node->next = node->next;
		new_node = new_node->next;
		node->next = new_node->next;
		node = node->next;
	}
	return new_head;
}

; ListNode* complicated(ListNode* head)
{
	Complicated_listnode(head);
	slide_connect(head);
	return reconnect(head);
}