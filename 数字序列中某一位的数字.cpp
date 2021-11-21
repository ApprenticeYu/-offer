#include<iostream>
using namespace std;

int get_begin(int first)
{
	if (first == 1)
	{
		return 0;
	}
	return (int)pow(10, first - 1);
}

int get_index(int number, int first)
{
	int begin_index = get_begin(first) + number / first;
	int begin_pos = first - number % first;
	for (int i = 1; i < begin_pos; i++)
	{
		begin_index /= 10;
	}
	return begin_index % 10;
}

int get_number(int first)
{
	if (first == 1)
	{
		return 10;
	}
	int result = (int)pow(10, first - 1);
	return 9 * result;
}

int The_number(int n)
{
	if (n < 0)
	{
		return -1;
	}
	int first = 1;
	while (true)
	{
		int number = get_number(first);
		if (n < first * number)
		{
			return get_index(n, first);
		}
		n -= first * number;
		first++;
	}
	return -1;
}