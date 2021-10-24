#include<iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
};

ListNode* search_k(ListNode* head, unsigned int k)
{
	if (head == nullptr || k == 0)
	{
		return nullptr;
	}
	ListNode* p_head = head;
	ListNode* p_behind = nullptr;
	for (int i = 0; i < k - 1; i++)
	{
		if (p_head->next != nullptr)
		{
			p_head = p_head->next;
		}
		else
		{
			return nullptr;
		}
	}
	p_behind = head;
	while (p_head->next != nullptr)
	{
		p_head = p_head->next;
		p_behind = p_behind->next;
	}
	return p_behind;
}