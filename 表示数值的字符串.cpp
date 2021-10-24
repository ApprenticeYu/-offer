#include<iostream>
using namespace std;

bool unsigned_integral(const char** str)
{
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
	{
		++(*str);
	}
	return *str > before;
}

bool integral(const char** str)
{
	if (**str == '+' || **str == '-')
	{
		++(*str);
	}
	return unsigned_integral(str);
}

bool is_numeric(const char* str)
{
	if (str == nullptr)
	{
		return false;
	}
	bool numeric = integral(&str);
	if (*str == '.')
	{
		++str;
		numeric = unsigned_integral(&str) || numeric;
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		numeric = numeric && integral(&str);
	}
	return numeric && (*str == '\0');
}

int main()
{
	const char* str = "+100";
	cout << is_numeric(str) << endl;
	system("pause");
	return 0;
}