#include<iostream>
using namespace std;

int get_first(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int middle = (start + end) / 2;
	int middle_value = data[middle];
	if (middle_value == k)
	{
		if ((middle > start && data[middle - 1] != k) || middle == start)
		{
			return middle;
		}
		else
		{
			end = middle - 1;
		}
	}
	else if (middle_value < k)
	{
		start = middle + 1;
	}
	else
	{
		end = middle - 1;
	}
	return get_first(data, length, k, start, end);
}

int get_last(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int middle = (start + end) / 2;
	int middle_value = data[middle];
	if (middle_value == k)
	{
		if ((middle < length - 1 && data[middle + 1] != k) || middle == length - 1)
		{
			return middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	else if (middle_value < k)
	{
		start = middle + 1;
	}
	else
	{
		end = middle - 1;
	}
	return get_last(data, length, k, start, end);
}

int get_times(int* data, int length, int k)
{
	int number = 0;
	if (data && length > 0)
	{
		int first = get_first(data, length, k, 0, length - 1);
		int last = get_last(data, length, k, 0, length - 1);
		if (first > -1 && last > -1)
		{
			number = last - first + 1;
		}
	}
	return number;
}