#include<iostream>
#include<vector>
using namespace std;

void array_mul(const vector<double>& array1, vector<double>& array2)
{
	int l1 = array1.size();
	int l2 = array2.size();
	if (l1 == l2 && l2 > 1)
	{
		array2[0] = 1;
		for (int i = 1; i < l2; i++)
		{
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		int temp = 1;
		for (int i = l2 - 2; i >= 0; i--)
		{
			temp *= array1[i + 1];
			array2[i] *= temp;
		}
	}
}