#include<iostream>
using namespace std;

template<typename T> void stack_with_min<T>::push(const T& value)
{
	min_data.push(value);
	if (min_stack.size() == 0 || value < min_stack.top())
	{
		min_stack.push(value);
	}
	else
	{
		min_stack.push(min_stack.top())
	}
}

template<typename T> void stack_with_min<T>::pop()
{
	assert(m_data.size() > 0 && m_stack.size() > 0);
	m_data.pop();
	m_stack.pop();
}

template<typename T> const T& stack_with_min<T>::min() const
{
	assert(m_data.size() > 0 && m_stack.size() > 0);
	return m_stack.top();
}