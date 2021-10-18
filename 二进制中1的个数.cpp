#include<iostream>
using namespace std;

int numer_of_1(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = n & (n - 1);
	}
	return count;
}

int main()
{
	cout << numer_of_1(9) << endl;
	system("pause");
	return 0;
}