#include<iostream>
using namespace std;

bool invalie_input = false;

int The_max_sum(int* data, int length)
{
	if ((data == nullptr) || (length <= 0))
	{
		invalie_input = true;
		return 0;
	}
	invalie_input = false;
	int max_current_sum = 0;
	int max_sum = 0x80000000;
	for (int i = 0; i < length; i++)
	{
		if (max_current_sum <= 0)
		{
			max_current_sum = data[i];
		}
		else
		{
			max_current_sum += data[i];
		}
		if (max_current_sum > max_sum)
		{
			max_sum = max_current_sum;
		}
	}
	return max_sum;

}