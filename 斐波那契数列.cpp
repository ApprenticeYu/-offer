#include<iostream>
using namespace std;

int Fibonacci(unsigned n)
{
	if (n < 2)
	{
		return n;
	}
	long long f1 = 1;
	long long f0 = 0;
	long long f2 = 0;
	for (int i = 2; i <= n; i++)
	{
		f2 = f1 + f0;
		f0 = f1;
		f1 = f2;
	}
	return f2;
}

int main()
{
	cout << Fibonacci(3) << endl;
	system("pause");
	return 0;
}