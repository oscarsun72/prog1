#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
using namespace std;//�d�U���n�ѤF�o��
struct  Sales_data {
	string bookNo;
	double revenue{ 0.00 };//�`�禬-��~�B
	unsigned soldQ{ 0 };
	double bookSize{0.00};
	Sales_data& combine(const Sales_data&, const Sales_data&);//�����禡�ŧi�@�w�n�b���O���A�w�q�i�b���~
	Sales_data& combine(const Sales_data&);//�����禡�ŧi�@�w�n�b���O���A�w�q�i�b���~
	string isbn()const;	
	double avg_price(const Sales_data&)const;
};
#endif // !SALES_DATA_H


