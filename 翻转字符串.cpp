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

char* reverse_core(char* data)
{
	if (data == nullptr)
	{
		return nullptr;
	}
	char* begin = data;
	char* end = data;
	while (*end != '\0')
	{
		end++;
	}
	--end;
	reverse(begin, end);
	begin = end = data;
	while (*begin != '\0')
	{
		if (*end == ' ' || *end == '\0')
		{
			reverse(begin, --end);
			begin = ++end;
		}
		else if (*begin == ' ')
		{
			++begin;
			++end;
		}
		else
		{
			++end;
		}
	}
	return data;
}