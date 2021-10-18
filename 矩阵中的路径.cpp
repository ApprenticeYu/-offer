#include<iostream>
using namespace std;

bool  has_path_core(const char* matrix, int rows, int columns, int row, int column, const char* str, bool* visited, int& path_length)
{
	if (str[path_length] == '\0')
	{
		return true;
	}
	bool path = false;
	if (row >= 0 && row < rows && column >= 0 && column < columns && matrix[row * columns + column] == str[path_length] && !visited[row * columns + column])
	{
		++path_length;
		visited[row * columns + column] = true;
		path = has_path_core(matrix, rows, columns, row + 1, column, str, visited, path_length) || has_path_core(matrix, rows, columns, row - 1, column, str, visited, path_length) || has_path_core(matrix, rows, columns, row, column + 1, str, visited, path_length) || has_path_core(matrix, rows, columns, row, column - 1, str, visited, path_length);
	}
	if (!path)
	{
		--path_length;
		visited[row * columns + column] = false;
	}
	return path;
}

bool has_path(const char* matrix, int rows, int columns,const char* str)
{
	if (matrix == nullptr || rows < 1 || columns < 1 || str == nullptr)
	{
		return false;
	}
	bool* visited = new bool[rows * columns];
	memset(visited, 0, columns * rows);
	int path_length = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int column = 0; column < columns; ++column)
		{
			if (has_path_core(matrix, rows, columns, row, column, str, visited, path_length))
			{
				return true;
			 }
		}
	}
	delete[] visited;
	return false;
}

int main()
{
	const char* matrix = "abtgcfcsjdeh";
	const char* str = "bfce";
	cout << has_path(matrix, 3, 4, str) << endl;
	system("pause");
	return 0;
}