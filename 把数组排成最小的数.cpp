#include<iostream>
using namespace std;

const int max_length = 10;
char* str1 = new(char[max_length * 2 + 1]);
char* str2 = new(char[max_length * 2 + 1]);

int compare(const void* str11, const void* str22)
{
	strcpy(str1, *(const char**)str11);
	strcat(str1, *(const char**)str22);

	strcpy(str2, *(const char**)str22);
	strcat(str2, *(const char**)str11);

	return strcmp(str1, str2);
}

void print_min_number(int* number, int length)
{
	if (number == nullptr || length <= 0)
	{
		return;
	}
	char** str3 = (char**)new(int[length]);
	for (int i = 0; i < length; i++)
	{
		str3[i] = new(char[max_length + 1]);
		sprintf(str3[i], "%d", number[i]);
	}
	qsort(str3, length, sizeof(char*), compare);

	for (int i = 0; i < length; i++)
	{
		printf("%s", str3[i]);
	}
	printf("\n");
	for (int i = 0; i < length; i++)
	{
		delete []str3[i];
	}
	delete[]str3;
}