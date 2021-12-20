#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> max_queue(const vector<int>& nums, unsigned int n)
{
	vector<int> result;
	if (nums.size() >= n && n >= 1)
	{
		deque<int> index;
		for (unsigned int i = 0; i < n; i++)
		{
			while (!index.empty() && nums[i] >+ nums[index.back()])
			{
				index.pop_back();
			}
			index.push_back(i);
		}
		for (unsigned int i = n; i < nums.size(); i++)
		{
			result.push_back(nums[index.front()]);
			while (!index.empty() && nums[i] > nums[index.back()])
			{
				index.pop_back();
			}
			if (!index.empty() && index.front() <= int(i - n))
			{
				index.pop_front();
			}
			index.push_back(i);
		}
		result.push_back(nums[index.front()]);
	}
	return result;
}