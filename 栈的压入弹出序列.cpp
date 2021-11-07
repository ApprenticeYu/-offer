#include<iostream>
#include<stack>
using namespace std;

class Solution
{
public:
	bool is_push(const int* push, const int* pop,int length)
	{
		bool possible = false;
		if (push != nullptr && pop != nullptr && length > 0)
		{
			const int* next_push = push;
			const int* next_pop = pop;
			stack<int> p_stack;
			while (next_pop - pop < length)
			{
				while (p_stack.empty() || p_stack.top() != *next_pop)
				{
					if (next_push - push >= length)
					{
						break;
					}
					p_stack.push(*next_push);
					++next_push;
				}
				if (p_stack.top() != *next_pop)
				{
					break;
				}
				p_stack.pop();
				++next_pop;
			}
			if (next_pop - pop == length && p_stack.empty())
			{
				possible = true;
			}
		}
		return possible;
	}
};