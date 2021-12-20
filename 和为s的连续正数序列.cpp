#include<iostream>
using namespace std;

void print_sequence(int small, int big)
{
	for (int i = small; i <= big; i++)
	{
		printf("%d", i);
		printf("\n");
	}
}

void s_sequence(int target)
{
	if (target < 3)
	{
		return;
	}
	int small = 1;
	int big = 2;
	int cur_sum = small + big;
	int middle = (target + 1) / 2;
	while (small < middle)
	{
		if (cur_sum == target)
		{
			print_sequence(small, big);
		}
		while ((small < middle) && (cur_sum > target))
		{
			cur_sum -= small;
			small += 1;

			if (cur_sum == target)
			{
				print_sequence(small, big);
			}
		}
		big += 1;
		cur_sum += big;
	}
}