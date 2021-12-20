#include<iostream>
#include<deque>
using namespace std;

template<typename T> class Queue_max
{
private:
	struct Internal_data
	{
		T number;
		int index;
	};
	deque<Internal_data> data;
	deque<Internal_data>maximum;
	int current_index;

public:
	Queue_max() :current_index(0)
	{

	};
	void push_back(T number)
	{
		while (!maximum.empty() && number >= maximum.back().number)
		{
			maximum.pop_back();
		}
		Internal_data internal = { number,current_index };
		data.push_back(internal);
		maximum.push_back(internal);
		current_index++;
	}
	void pop_back()
	{
		if (maximum.empty())
		{
			throw new exception("Invalid!");
		}
		if (maximum.front().index == data.front().index)
		{
			maximum.pop_front();
		}
		data.pop_front();
	}
	T max() const
	{
		if (maximum.empty())
		{
			throw new exception("Invalid!");
		}
		return maximum.front().number;
	}
};