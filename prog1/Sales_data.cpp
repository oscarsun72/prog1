#include "Sales_data.h"
#include<string>
using namespace std;
Sales_data& Sales_data::combine(const Sales_data& sales_data1,  const Sales_data& sales_data2)
{
	this->bookNo = sales_data1.bookNo;
	this->bookSize = sales_data1.bookSize;
	this->soldQ = sales_data1.soldQ + sales_data2.soldQ;
	this->revenue = sales_data1.revenue + sales_data2.revenue;
	return *this; // TODO: insert return statement here
}
Sales_data& Sales_data::combine(const Sales_data& sales_data)
{
	if (bookNo == "") bookNo = sales_data.bookNo;//�]���o�OSales_data���O�������禡�A�ҥH�i�H�����եθ����O�����Ҧ������W�١A�������W��
	bookSize = sales_data.bookSize;
	soldQ += sales_data.soldQ;
	revenue += sales_data.revenue;
	return *this;// TODO: insert return statement here
}
string Sales_data::isbn()const
{
	return bookNo;
}

double Sales_data::avg_price()const
{
	if (soldQ>0)
	{
		return revenue / soldQ;
	}
	return 0.0;
}
