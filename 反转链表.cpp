#include<iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
};

class Solution
{
public:
	ListNode* reverse_listnode(ListNode* head)
	{
		ListNode* reverse_head = nullptr;
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur)
		{
			ListNode* next = cur->next;
			if (next == nullptr)
			{
				reverse_head = cur;
			}
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return reverse_head;
	}
};