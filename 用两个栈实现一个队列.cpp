#include<iostream>
using namespace std;

template<typename T> class Cque
{
public:
	void Cque();
	void ~Cque();
	void add_tail(const T& node);
	T delete_head();

private:
	stack<T>stack1;
	stack<T>stack2;
};

template<typename T> void Cque <T>::add_tail(const T& node)
{
	stack1.push(node);
}

template<typename T> T Cque<T>::delete_head()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
		
	}
	if (stack2.size() == 0)
	{
		throw new exception("Empty queue!");
	}
	T& temp2 = stack2.top();
	stack2.pop();
	return temp2;
}