#include<iostream>
using namespace std;

bool Increment(char* number)
{
	bool over = false;
	int take = 0;
	int n = strlen(number);
	for (int i = n - 1; i >= 0; i--)
	{
		int num = number[i] - '0' + take;
		if (i == n - 1)
		{
			num++;
		}
		if (num >= 10)
		{
			if (i == 0)
			{
				over = true;
			}
			else
			{
				num -= 10;
				take = 1;
				number[i] = num + '0';
			}
		}
		else
		{
			number[i] = num + '0';
			break;
		}
	}
	return over;
}

void Print_num(char* number)
{
	bool begin0 = true;
	int n = strlen(number);
	for (int i = 0; i < n; i++)
	{
		if (begin0 && number[i] != '0')
		{
			begin0 = false;
		}
		if (!begin0)
		{
			cout << number[i];
		}
	}
	cout << endl;
}

void print_max_n(int n)
{
	if (n <= 0)
	{
		return;
	}
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number))
	{
		Print_num(number);
	}
	delete[] number;
	return;
}

void backtrack(char* number, int length, int index)
{
	if (index == length - 1)
	{
		Print_num(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		backtrack(number, length, index + 1);
	}
}

void print_max_n_2(int n)
{
	if (n <= 0)
	{
		return;
	}
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		backtrack(number, n, 0);
	}
	delete[] number;
	return;
}

int main()
{
	print_max_n_2(2);
	system("pause");
	return 0;
}