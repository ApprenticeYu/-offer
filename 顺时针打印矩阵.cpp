#include<iostream>
using namespace std;

void print(int number)
{
	cout << number;
}

void print_matrix_core(int** num, int rows, int columns, int start)
{
	int X = columns - 1 - start;
	int Y = rows - 1 - start;
	int number = 0;
	for (int i = start; i <= X; i++)
	{
		number = num[start][i];
		print(number);
	}
	if (start < Y)
	{
		for (int i = start + 1; i <= Y; i++)
		{
			number = num[i][X];
			print(number);
		}
	}
	if (start < X && start < Y)
	{
		for (int i = X - 1; i >= start; i--)
		{
			number = num[Y][i];
			print(number);
		}
	}
	if (start < X && start < Y - 1)
	{
		for (int i = Y - 1; i > start; i--)
		{
			number = num[i][start];
			print(number);
		}
	}
}

void print_matrix(int** num, int rows, int columns)
{
	if (num == nullptr || rows <= 0 || columns <= 0)
	{
		return;
	}
	int start = 0;
	while (rows > start * 2 && columns > start * 2)
	{
		print_matrix_core(num, rows, columns, start);
		++start;
	}
}