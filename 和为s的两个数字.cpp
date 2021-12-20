#include<iostream>
using namespace std;

bool find_numbers_sum(int data[], int length, int target, int* num1, int* num2)
{
	bool find = false;
	if (num1 == nullptr || num2 == nullptr || length < 2)
	{
		return false;
	}
	int left = 0;
	int right = length - 1;
	while (left < right)
	{
		long long cursum = data[left] + data[right];
		if (cursum == target)
		{
			*num1 = data[left];
			*num2 = data[right];
			find = true;
			break;
		}
		else if (cursum > target)
		{
			right--;
		}
		else
		{
			left++;
		}
	}
	return find;
}