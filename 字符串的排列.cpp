#include<iostream>
using namespace std;

void sequence_core(char* str, char* begin)
{
	if (*begin == '\0')
	{
		printf("%s\n", str);
		return;
	}
	for (char* ch = begin; *ch != '\0'; ++ch)
	{
		char temp = *ch;
		*ch = *begin;
		*begin = temp;
		sequence_core(str, begin + 1);

		temp = *begin;
		*begin = *ch;
		*ch = temp;
	}
}

void sequence(char* str)
{
	if (!str)
	{
		return;
	}
	sequence_core(str, str);
}

void main()
{
	char str[] = "abc";
	sequence(str);
	system("pause");
}