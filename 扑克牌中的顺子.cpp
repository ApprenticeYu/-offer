#include<iostream>
using namespace std;

int compare(const void* arg1, const void* arg2)
{
	return (*(int*)arg1 - *(int*)arg2);
}

bool is_sequence(int* data, int length)
{
	if (data == nullptr || length < 1)
	{
		return false;
	}
	qsort(data, length, sizeof(int), compare);
	int num_of_zero = 0;
	int num_od_gap = 0;
	for (int i = 0; i < length && data[i] == 0; i++)
	{
		num_of_zero++;
	}
	int small = num_of_zero;
	int big = small + 1;
	while (big < length)
	{
		if (data[small] == data[big])
		{
			return false;
		}
		num_od_gap += data[big] - data[small] - 1;
		small = big;
		big++;
	}
	return (num_od_gap > num_of_zero) ? false : true;
}