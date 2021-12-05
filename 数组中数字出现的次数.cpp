#include<iostream>
using namespace std;

unsigned int index_of_1(int total)
{
	unsigned int bit = 0;
	if (((total & 1) == 0) && bit < 8 * sizeof(int))
	{
		total >>= 1;
		bit++;
	}
	return bit;
}

bool is_1(int number, unsigned int index)
{
	number >>= index;
	return (number & 1);
}

void once_number(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length < 2)
	{
		return;
	}
	int total = 0;
	for (int i = 0; i < length; i++)
	{
		total ^= data[i];
	}
	unsigned int index = index_of_1(total);
	*num1 = *num2 = 0;
	for (int i = 0; i < length; i++)
	{
		if (is_1(data[i], index))
		{
			*num1 ^= data[i];
		}
		else
		{
			*num2 ^= data[i];
		}
	}
}