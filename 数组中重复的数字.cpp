/*
#include <iostream>
using namespace std;

bool is_duplicate(int numbers[], int length, int& duplicate)
{
	if (numbers == nullptr || length <= 0)
	{
		return false;

	}
	for (int i = 0; i < length; i++)
	{

		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}
	for (int i = 0; i < length; i++)
	{

		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				duplicate = numbers[i];
				return true;

			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;

		}
	}
	return false;

}
int main()
{
	int duplication;
	int numbers[7] = { 2,3,1,0,2,5,3 };
	cout << is_duplicate(numbers, 7, duplication) << endl;
	cout << duplication << endl;
	system("pause");
	return 0;

}
*/