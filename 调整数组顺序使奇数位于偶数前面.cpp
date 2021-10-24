#include<iostream>
using namespace std;

bool is_oven(int n)
{
	return (n & 1) == 0;
}

void adjust_array(int* data, unsigned int length, bool(*func)(int))
{
	if (data == nullptr || length == 0)
	{
		return;
	}
	int* p_begin = data;
	int* p_end = data + length - 1;
	while (p_begin < p_end)
	{
		while (p_begin < p_end && !func(*p_begin))
		{
			++p_begin;
		}
		while (p_begin < p_end && func(*p_end))
		{
			--p_end;
		}
		if (p_begin < p_end)
		{
			int temp = *p_begin;
			*p_begin = *p_end;
			*p_end = temp;
		}
	}
	return;
}