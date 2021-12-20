#include<iostream>
using namespace std;

int only_once(int data[], int length)
{
	if (data == nullptr || length <= 0)
	{
		throw new exception("Invalid input !");
	}
	int bits[32] = { 0 };
	for (int i = 0; i < length; i++)
	{
		int mask = 1;
		for (int j = 31; j >= 0; j--)
		{
			int bit = data[i] & mask;
			if (bit == 1)
			{
				bits[j]++;
			}
			mask <<= 1;
		}
	}
	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		result <<= 1;
		result += bits[i] % 3;
	}
	return result;
}