#include<iostream>
using namespace std;

int last_number(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	int result = 0;
	for (int i = 2; i <= n; i++)
	{
		result = (0result + m) % i;
	}
	return result;
}