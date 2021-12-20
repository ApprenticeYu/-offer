#include<iostream>
using namespace std;

void reverse(char* begin, char* end)
{
	if (begin == nullptr || end == nullptr)
	{
		return;
	}
	while (begin < end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;

		begin++;
		end--;
	}
}

char* left_reverse(char* s, int n)
{
	if (s != nullptr)
	{
		int length = static_cast<int>(strlen(s));
		if (length > 0 && n > 0 && n < length)
		{
			char* first_begin = s;
			char* first_end = s + n - 1;
			char* second_begin = s + n;
			char* second_end = s + length - 1;
			reverse(first_begin, first_end);
			reverse(second_begin, second_end);
			reverse(s, s + length - 1);
		}
	}
	return s
}