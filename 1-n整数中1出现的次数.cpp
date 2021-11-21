#include<iostream>
using namespace std;

int power(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}

int The_number_of_1_core(const char* str)
{
	if (!str || (*str < '0') || (*str > '9') || (*str == '\0'))
	{
		return 0;
	}
	int first = *str - '0';
	unsigned int length = static_cast<unsigned int>(strlen(str));
	if (first == 0 && length == 1)
	{
		return 0;
	}
	if (first > 0 && length == 1)
	{
		return 1;
	}
	int number_of_1_first = 0;
	int number_of_1_second = 0;
	int number_of_1_other = 0;
	if (first > 1)
	{
		number_of_1_first = power(length - 1);
	}
	else if(first == 1)
	{
		number_of_1_first = atoi(str + 1) + 1;
	}
	number_of_1_second = first * (length - 1) * power(length - 2);
	number_of_1_other = The_number_of_1_core(str + 1);
	return number_of_1_first + number_of_1_other + number_of_1_second;
}

int The_number_of_1(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	char str_n[50];
	sprintf(str_n, "%d", n);
	return The_number_of_1_core(str_n);
}