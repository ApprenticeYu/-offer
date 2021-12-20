#include<iostream>
using namespace std;

class Solution
{
public:
	Solution()
	{
		N++;
		SUM += N;
	}
	static void reset()
	{
		N = 0;
		SUM = 0;
	}
	static unsigned int get_sum()
	{
		return SUM;
	}
private:
	static unsigned int N;
	static unsigned int SUM;
};

unsigned int Solution::N = 0;
unsigned int Solution::SUM = 0;

unsigned int SUM_Solution(unsigned int n)
{
	Solution* temp = new Solution[n];
	delete[]temp;
	temp = nullptr;
	return Solution::get_sum();
}

class A;
A* Array[2];
class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B:public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int Sum_solution(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	return Array[1]->Sum(n);
}

typedef unsigned int (*func) (unsigned int n);
unsigned int Solution_terminator(unsigned int n)
{
	return 0;
}
unsigned int Solution_(unsigned int n)
{
	static func dp[2] = {Solution_terminator ,Solution_};
	return n + dp[!!n](n - 1);
}

template<unsigned int> struct Solution4
{
	enum Value {N = Solution4<n - 1>::N + n};
};

template<> struct Solution4<1>
{
	enum Value {N = 1};
};