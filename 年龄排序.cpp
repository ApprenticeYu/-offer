#include<iostream>
using namespace std;

void age_sort(int ages[], int length)
{
	if (ages == nullptr || length <= 0)
	{
		return;
	}
	const int oldest = 99;
	int age[oldest + 1];
	for (int i = 0; i <= oldest; i++)
	{
		age[i] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		int temp = ages[i];
		if (temp < 0 || temp > oldest)
		{
			throw new exception("Out of range!");
		}
		++age[temp];
	}
	int index = 0;
	for (int i = 0; i <= oldest; i++)
	{
		for (int j = 0; j < age[i]; j++)
		{
			ages[index] = i;
			++index;
		}
	}
}

int main()
{
	int ages[] = { 1,23,34,64,65,76,34,66,32,55,77 };
	age_sort(ages, 11);
	for (int i = 0; i < 11; i++)
	{
		cout << ages[i] << endl;
	}
	system("pause");
	return 0;
}