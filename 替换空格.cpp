#include<iostream>
using namespace std;

void replaceblank(char s[], int length)
{

	if (s == nullptr || length <= 0)
	{

		return;
	}
	int lengthofstring = 0;
	int i = 0;
	int lengthofblank = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
		{

			lengthofblank++;
		}
		lengthofstring++;
		i++;

	}
	int lengthofnew = lengthofstring + 2 * lengthofblank;
	if (lengthofnew > length)
	{

		return;
	}
	int indexoforiginal = lengthofstring;
	int indexofnew = lengthofnew;
	while (indexoforiginal >= 0 && indexoforiginal < indexofnew)
	{

		if (s[indexoforiginal] == ' ')
		{
			--indexoforiginal;
			s[indexofnew--] = '0';
			s[indexofnew--] = '2';
			s[indexofnew--] = '%';

		}
		else
		{
			s[indexofnew--] = s[indexoforiginal--];
		}
	}
	return;
}

int main()
{
	char s[20] = "we are happy.";
	replaceblank(s, 20);
	cout << s << endl;
	system("pause");
	return 0;
}