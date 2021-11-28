#include<iostream>
using namespace std;

int MIN(int ugly_2, int ugly_3, int ugly_5)
{
	int result = (ugly_2 < ugly_3) ? ugly_2 : ugly_3;
	return (result < ugly_5) ? result : ugly_5;
}

int Ugly(int index)
{
	if (index <= 0)
	{
		return 0;
	}
	int* ugly_number = new int[index];
	ugly_number[0] = 1;
	int next_index = 1;
	int* ugly_2 = ugly_number;
	int* ugly_3 = ugly_number;
	int* ugly_5 = ugly_number;
	while (next_index < index)
	{
		int min_number = MIN(*ugly_2 * 2, *ugly_3 * 3, *ugly_5 * 5);
		ugly_number[next_index] = min_number;
		while (*ugly_2 * 2 <= ugly_number[next_index])
		{
			++ugly_2;
		}
		while (*ugly_3 * 3 <= ugly_number[next_index])
		{
			++ugly_3;
		}
		while (*ugly_5 * 5 <= ugly_number[next_index])
		{
			++ugly_5;
		}
		++next_index;
	}
	int ans = ugly_number[index - 1];
	delete[] ugly_number;
	return ans;
}