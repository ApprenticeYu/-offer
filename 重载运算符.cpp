#include<iostream>
using namespace std;

class CMyString
{
private:
	char* p_data;
public:
	CMyString(char* p_data = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

};
CMyString& CMyString::operator =(const CMyString& str)
{

	if (this != &str)
	{
		CMyString temp(str);
		char* temp_string = temp.p_data;
		temp.p_data = p_data;
		p_data = temp_string;
	}
	return *this;
}