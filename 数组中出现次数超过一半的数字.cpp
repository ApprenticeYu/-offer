#include<iostream>
using namespace std;

bool invalid_sign = false;

bool check_invalid(int* numbers, int length)
{
	invalid_sign = false;
	if (numbers == nullptr || length <= 0)
	{
		invalid_sign = true;
	}
	return invalid_sign;
}

bool check_more_half(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (number == numbers[i])
		{
			++times;
		}
	}
	bool more_sign = true;
	if (times * 2 <= length)
	{
		more_sign = false;
		invalid_sign = true;
	}
	return more_sign;
}

int more_than_half(int* numbers, int length)
{
	if (!check_invalid(numbers, length))
	{
		int result = numbers[0];
		int times = 1;
		for(int i = 1; i < length; i++)
		{
			if (times == 0)
			{
				result = numbers[i];
				times = 1;
			}
			else if (result == numbers[i])
			{
				++times;
			}
			else
			{
				--times;
			}
		}
		if (check_more_half(numbers, length, result))
		{
			return result;
		}
	}
	return 0;
}