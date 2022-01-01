#include<iostream>
using namespace std;

class Solution
{
public:
	int Add(int add1, int add2)
	{
		do
		{
			int sum = add1 ^ add2;
			int carry = (add1 & add2) << 1;
			add1 = sum;
			add2 = carry;
		} while (add2 != 0);
		return add1;
	}
};