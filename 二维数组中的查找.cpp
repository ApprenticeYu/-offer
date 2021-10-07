#include<iostream>
using namespace std;

bool find_array(int* matrix, int rows, int columns, int number)
{

	bool find_result = false;
	if (matrix != nullptr && rows > 0 && columns > 0)
	{

		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{

			if (matrix[columns * row + column] == number)
			{

				find_result = true;
				break;
			}
			else if (matrix[columns * row + column] > number)
			{

				--column;
			}
			else
			{

				++row;
			}
		}
		return find_result;
	}
	
}

int main()
{

	int matrix[16] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	cout << find_array(matrix, 4, 4, 7) << endl;
	system("pause");
	return 0;
}