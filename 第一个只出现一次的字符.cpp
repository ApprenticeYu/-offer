#include<iostream>
using namespace std;

char first_letter(char* s)
{
	if (s == nullptr)
	{
		return '\0';
	}
	const int total = 256;
	unsigned int hash_map[total];
	for (int i = 0; i < total; i++)
	{
		hash_map[i] = 0;
	}
	char* temp = s;
	while (*temp != '\0')
	{
		hash_map[*(temp++)]++;
	}
	temp = s;
	while (*temp != '\0')
	{
		if (hash_map[*temp] == 1)
		{
			return *temp;
		}
		++temp;
	}
	return '\0';
}