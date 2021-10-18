#include<iostream>
using namespace std;

double power_of_number_core(double exponent, unsigned int base)
{
	if (base == 0)
	{
		return 1;
	}
	if (base == 1)
	{
		return exponent;
	}
	double result = power_of_number_core(exponent, base >> 1);
	result *= result;
	if (base & 0x1 == 1)
	{
		result *= exponent;
	}
	return result;
}

bool invalid_input = false;
double power_of_number(double exponent, int base)
{
	invalid_input = false;
	if ((abs(exponent - 0) < 1e-8) && base < 0)
	{
		invalid_input = true;
		return 0.0;
	}
	unsigned int abs_base = (unsigned int)(base);
	if (base < 0)
	{
		abs_base = (unsigned int)(-base);
	}
	double ans = power_of_number_core(exponent, abs_base);
	if (base < 0)
	{
		ans = 1.0 / ans;
	}
	return ans;
}

int main()
{
	cout << power_of_number(-1, -1) << endl;
	system("pause");
	return 0;
}