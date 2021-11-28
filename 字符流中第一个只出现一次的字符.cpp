#include<iostream>
using namespace std;

class Solution
{
private:
	int occurence[256];
	int index;

public:
	Solution() :index(0)
	{
		for (int i = 0; i < 256; i++)
		{
			occurence[i] = -1;
		}
	}

	void insert(char ch)
	{
		if (occurence[ch] == -1)
		{
			occurence[ch] = index;
		}
		else if (occurence[ch] >= 0)
		{
			occurence[ch] = -2;
		}
		++index;
	}

	char first_once()
	{
		char ch = '\0';
		int min_index = numeric_limits<int>::max();
		for (int i = 0; i < 256; i++)
		{
			if (occurence[i] >= 0 && occurence[i] < min_index)
			{
				ch = (char)i;
				min_index = occurence[i];
			}
		}
		return ch;
	}
};