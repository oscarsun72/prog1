#include "StrBlob.h"
#include<memory>//make_shared �n��
#include <stdexcept>//out_of_range �n��
using namespace std;
//StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob()
{
	data = make_shared<vector<string>>();
}
//StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}//��il�ӧ@��make_shared�޼ơA�N���O�Ū�vector�F
StrBlob::StrBlob(initializer_list<string> il)
{
	data = make_shared<vector<string>>(il);
}

void StrBlob::check(size_type i, const string& msg) const
{
	if (i>=data->size())
	{
		throw out_of_range(msg);//���ޥ�stdexcept���Y #include <stdexcept>
	}
}

void StrBlob::pop_back()
{
	check(0, "pop_back on an empty StrBlob");
	data->pop_back();
}

string& StrBlob::front()
{
	check(0, "front on an empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back() on an empty StrBlob");
	return data->back();
}
