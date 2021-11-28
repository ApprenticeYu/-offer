#include<iostream>
using namespace std;

int reverse_numbers_core(int* data, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}
	int length = (end - start) / 2;
	int left = reverse_numbers_core(data, copy, start, start + length);
	int right = reverse_numbers_core(data, copy, start + length + 1, end);
	int count = 0;
	int i = start + length;
	int j = end;
	int copy_index = end;
	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[copy_index--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[copy_index--] = data[j--];
		}
	}
	for (; i >= start; i--)
	{
		copy[copy_index--] = data[i];
	}
	for (; j >= start + length + 1; j--)
	{
		copy[copy_index--] = data[j];
	}
	return left + right + count;
}

int veverse_numbers(int* data, int length)
{
	if (data == nullptr || length < 0)
	{
		return 0;
	}
	int* copy = new int[length];
	for (int i = 0; i < length; i++)
	{
		copy[i] = data[i];
	}
	int n = reverse_numbers_core(data, copy, 0, length - 1);
	delete[]copy;
	return n;
}