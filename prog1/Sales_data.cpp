#include "Sales_data.h"
#include<string>
#include<iostream>
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
ostream& print(ostream& os, Sales_data sales_data) {
	os << sales_data.isbn() << '\t' << sales_data.soldQ << '\t'
		<< sales_data.revenue << '\t' << sales_data.avg_price();
	return os;
}

istream& read(istream& is, Sales_data& sales_data) {//�n���ܤ޼ƭȡA�ѼƤ@�w�n�O�ѦҡA�N�޼ƥζǧ}�]�Ѧҡ^�覡�ǻ�
//decltype(cin)& read(istream is ,Sales_data sales_data) {
	is >> sales_data.bookNo >> sales_data.soldQ >> sales_data.revenue;
	return is;
}

Sales_data add(const Sales_data& sales_data1, const Sales_data& sales_data2)
{
	Sales_data sum = sales_data1;
	sum.combine(sales_data2);
	return sum;
}
