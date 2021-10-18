#include<iostream>
using namespace std;

int get_sum(int num)
{
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;

}

bool check(int& threshold, int& rows, int& columns, int row, int column, bool* visited)
{
	if (row >= 0 && row < rows && column >= 0 && column < columns && get_sum(row) + get_sum(column) <= threshold && !visited[row * columns + column])
	{
		return true;
	}
	return false;
}

int sport_range_core(int& threshold, int& rows, int& columns, int row, int column, bool* visited)
{
	int count = 0;
	if (check(threshold, rows, columns, row, column, visited))
	{
		visited[row * columns + column] = true;
		count = 1 + sport_range_core(threshold, rows, columns, row + 1, column, visited) + sport_range_core(threshold, rows, columns, row - 1, column, visited) + sport_range_core(threshold, rows, columns, row, column + 1, visited) + sport_range_core(threshold, rows, columns, row, column - 1, visited);
	}
	return count;
}

int sport_range(int threshold, int rows, int columns)
{
	if (threshold < 0 || rows <= 0 || columns <= 0)
	{
		return 0;
	}
	bool* visited = new bool[rows * columns];
	for (int i = 0; i < rows * columns; i++)
	{
		visited[i] = false;
	}
	int count = sport_range_core(threshold, rows, columns, 0, 0, visited);
	delete[] visited;
	return count;
}

int main()
{
	cout << sport_range(18, 40, 40) << endl;
	system("pause");
	return 0;
}