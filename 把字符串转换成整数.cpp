#include<iostream>
using namespace std;

enum Status {g_valid = 0,g_invalid};
int g_status = g_valid;

long long str_to_int_core(const char* str, bool minus)
{
	long long num = 0;
	while(*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 0 + (*str - '0');

			if ((!minus && num > 0x7FFFFFFF) || (minus && num < 0x80000000))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*str == '\0')
	{
		g_status = g_valid;
	}
	return num;
}

int str_to_int(const char* str)
{
	g_status = g_invalid;
	long long num = 0;
	if (str != nullptr && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
		{
			str++;
		}
		else if (*str == '-')
		{
			str++;
			minus = true;
		}
		if (*str != '\0')
		{
			num = str_to_int_core(str, minus);
		}
	}
	return (int)num;
}