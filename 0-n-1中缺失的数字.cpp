#include<iostream>
using namespace std;

int miss_number(const int* data, int length)
{
	if (data == nullptr || length <= 0)
	{
		return -1;
	}
	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = (left + right) >> 1;
		if (data[middle] != middle)
		{
			if (middle == 0 || (middle > 0 && data[middle - 1] == middle - 1))
			{
				return middle;
			}
			else
			{
				right = middle - 1;
			}
		}
		else
		{
			left = middle + 1;
		}
	}
	if (left == length)
	{
		return length;
	}
	return -1;
}