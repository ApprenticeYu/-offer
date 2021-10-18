#include <iostream>
using namespace std;

int sequence_min(int* numbers, int left, int right)
{
	int result = numbers[left];
	for (int i = left + 1; i <= right; i++)
	{
		if (result > numbers[i])
		{
			result = numbers[i];
		}
	}
	return result;
}

int rotate_min(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		throw new exception("Tnvalid Parameters!");
	}
	int left = 0;
	int right = length - 1;
	int mid_index = left;
	while (numbers[left] >= numbers[right])
	{
		if (right - left == 1)
		{
			mid_index = right;
			break;
		}
		mid_index = (left + right) / 2;
		if (numbers[left] == numbers[mid_index] && numbers[left] == numbers[right])
		{
			return sequence_min(numbers, left, right);
		}
		if(numbers[left] <= numbers[mid_index])
		{
			left = mid_index;
		}
		else if(numbers[mid_index] <= numbers[right])
		{
			right = mid_index;
		}
	}
	return numbers[mid_index];
}

int main()
{
	int numbers[] = { 3,4,5,1,2 };
	cout << rotate_min(numbers, 5) << endl;
	system("pause");
	return 0;
}
