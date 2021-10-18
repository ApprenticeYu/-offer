#include<iostream>
using namespace std;

int cut_string(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;
	for (int i = 4; i <= length; i++)
	{
		int max = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			int product = products[j] * products[i - j];
			if (max < product)
			{
				max = product;
			}
		}
		products[i] = max;
	}
	int result = products[length];
	delete[] products;
	return result;

}

int cut_string_solution2(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}
	int times_of_3 = length / 3;
	if (length - times_of_3 * 3 == 1)
	{
		times_of_3--;
	}
	int time_of_2 = (length - times_of_3 * 3) / 2;
	return (int)(pow(3, times_of_3)) * (int)(pow(2, time_of_2));
}

int main()
{
	cout << cut_string_solution2(5) << endl;
	system("pause");
	return 0;
}