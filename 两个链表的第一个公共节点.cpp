#include<iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
};

unsigned int get_length(ListNode* head)
{
	unsigned int count = 0;
	ListNode* node = head;
	while (node)
	{
		++count;
		node = node->next;
	}
	return count;
}

ListNode* common_node(ListNode* head1, ListNode* head2)
{
	unsigned int length1 = get_length(head1);
	unsigned int length2 = get_length(head2);
	
	ListNode* long_list = head1;
	ListNode* short_list = head2;
	int diff = length1 - length2;

	if (length2 > length1)
	{
		long_list = head2;
		short_list = head1;
		diff = length2 - length1;
	}

	for (int i = 0; i < diff; i++)
	{
		long_list = long_list->next;
	}

	while (long_list && short_list && (long_list != short_list))
	{
		long_list = long_list->next;
		short_list = short_list->next;
	}

	ListNode* result = long_list;
	return result;
}