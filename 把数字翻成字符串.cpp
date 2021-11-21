#include<iostream>
#include<string>
using namespace std;

int get_string(const string& n_str)
{
	int length = n_str.length();
	int* counts = new int[length];
	int count = 0;
	for (int i = length - 1; i >= 0; --i)
	{
		count = 0;
		if (i < length - 1)
		{
			count = counts[i + 1];
		}
		else
		{
			count = 1;
		}
		if (i < length - 1)
		{
			int left = n_str[i] - '0';
			int right = n_str[i + 1] - '0';
			int digit = left * 10 + right;
			if (digit >= 0 && digit <= 25)
			{
				if (i < length - 2)
				{
					count += counts[i + 2];
				}
				else
				{
					count += 1;
				}
			}
		}
		counts[i] = count;
	}
	count = counts[0];
	delete[]counts;
	return count;
}

int get_string(int n)
{
	if (n < 0)
	{
		return 0;
	}
	string n_str = to_string(n);
	return get_string(n_str);
}