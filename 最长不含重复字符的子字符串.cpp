#include<iostream>
using namespace std;

int max_subarray(const string& s)
{
	int cur_length = 0;
	int max_length = 0;
	int* position = new int[26];
	for (int i = 0; i < 26; i++)
	{
		int preindex = position[s[i] - 'a'];
		if (preindex < 0 || i - preindex > cur_length)
		{
			cur_length++;
		}
		else
		{
			if (cur_length > max_length)
			{
				max_length = cur_length;
			}
			cur_length = i - preindex;
		}
		position[s[i] - 'a'] = i;
	}
	if (cur_length > max_length)
	{
		max_length = cur_length;
	}
	delete[] position;
	return max_length;
}