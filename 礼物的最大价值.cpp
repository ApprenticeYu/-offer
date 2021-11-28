#include<iostream>
using namespace std;

int max_value(const int* value, int rows, int columns)
{
	if (value == nullptr || rows <= 0 || columns <= 0)
	{
		return 0;
	}
	int* value_temp = new int[columns];
	int up = 0;
	int left = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i > 0)
			{
				up = value_temp[j];
			}
			if (j > 0)
			{
				left = value_temp[j - 1];
			}
			value_temp[j] = max(up, left) + value[i * columns + j];
		}
	}
	int result = value_temp[columns - 1];
	delete[] value_temp;
	return result;
}