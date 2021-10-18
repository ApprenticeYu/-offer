#include<iostream>
using namespace std;

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int Partition(int data[], int length, int begin, int end)
{
	if (data == nullptr || length <= 0 || begin < 0 || end >= length)
	{
		throw new exception("Invalid Parameters!");
	}
	int index = begin + ((end - begin >> 1));
	int small = begin - 1;
	Swap(&data[index], &data[end]);
	for (int index = begin; index < end; index++)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				Swap(&data[small], &data[index]);
			}
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}
void Quicksort(int data[], int length, int begin, int end)
{
	if (begin == end)
	{
		return;
	}
	int index = Partition(data, length, begin, end);
	if (index > begin)
	{
		Quicksort(data, length, begin, index - 1);
	}
	if (index < end)
	{
		Quicksort(data, length, index + 1, end);
	}
}

int main()
{
	int data[] = { 1,3,4,6,8,9 };
	Quicksort(data, 6, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		cout << data[i];
	}
	cout << endl;
	system("pause");
	return 0;
}