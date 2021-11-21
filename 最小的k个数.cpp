#include<iostream>
#include<set>
#include<vector>
using namespace std;

typedef multiset<int, greater<int>> intset;
typedef multiset<int, greater<int>>::iterator intset_iter;
void least_numbers(const vector<int>& numbers, intset& data, int k)
{
	data.clear();
	if (numbers.size() < k || k < 1)
	{
		return;
	}
	for (vector<int>::const_iterator iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		if (data.size() < k)
		{
			data.insert(*iter);
		}
		else
		{
			intset_iter intset = data.begin();
			if (*iter < *intset)
			{
				data.erase(intset);
				data.insert(*iter);
			}
		}
	}
}