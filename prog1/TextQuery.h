﻿#ifndef TextQuery_H
#define TextQuery_H
#include<vector>
#include<memory>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>//要用getline函式，要引入這一行
#include<map>
#include<set>
#include "QueryResult.h"
using namespace std;
class TextQuery
{
	friend class QueryResult;
	typedef pair<map<string, size_t>::const_iterator, map<string, size_t>::const_iterator>
		pair_iterator_map;
	typedef pair<shared_ptr<vector<string>>, shared_ptr<pair<string, set<size_t>>>> pair_sp_vec_str_sp_pair_str_set;
	using iterator_map= map<string, set<size_t>>::iterator;
public:
	//TextQuery() ;
	TextQuery(ifstream& infile);
	~TextQuery();
	QueryResult query(const string&);
private:
	shared_ptr<vector<string>>spVs;//第89集 2:12:00
	//一個map關聯式容器(associative container)因為一個字詞key(string)會有好幾行與之對應，故用multimap	
	map<string, set<size_t>>word_lineNum;
	//set<size_t>lineNum;	
};

TextQuery::TextQuery(ifstream& infile)
{
	string lStr;
	size_t line_Num{ 0 };
	vector<string>vs;
	spVs = make_shared<vector<string>>(vs);
	while (infile && !infile.eof())//第89集2:4:00
	{
		getline(infile, lStr);
		spVs->push_back(lStr);//one line of text in an element		
		++line_Num;
		//lineNum.insert(line_Num);
		istringstream isstr(lStr);
		string word;
		while (isstr >> word)
		{
			map<string, set<size_t>>::iterator mIter = word_lineNum.find(word);			
			if (mIter == word_lineNum.end()) {//如果文字行號的map還沒有此文字的話
				set<size_t> line_num_st;
				line_num_st.insert(line_Num);
				word_lineNum.insert(make_pair(word, line_num_st));
			}
			else//如果文字行號的map已經有此文字的話
				mIter->second.insert(line_Num);
		}
	}
}

TextQuery::~TextQuery()
{
}

QueryResult TextQuery::query(const string& wordForQuery)
{
	/*第88集4:18:23//4:31:30回傳的應該是檢索結果，
	*用allocator物件記錄在動態記憶體(dynamic memory),再與QueryResult物件共用此資料*/
	//臉書直播第443集、444集。第89集1:18:00

	//檢索字串出現的行號集合中的第1個迭代器：回傳一對迭代器代表具有鍵值wordForQuery的那些元素。如果wordForQuery沒出現，那兩個成員都會是word_lineNum.end()。	
	//pair_iterator_map wlIter = word_lineNum.equal_range(wordForQuery);
	iterator_map wlIter = word_lineNum.find(wordForQuery);
	cout << word_lineNum.count(wordForQuery) << endl;
	if (wlIter == word_lineNum.end())
	{
		cout << "沒有找到您要找的字串！" << endl; 
		QueryResult qr;
		return qr;
	}	
	//找到了就要準備印出檢索結果 第89集1:23:00
	//allocator<map<string, set<size_t>>> avs=;
	////avs.allocate((wlIter.second));
	//uninitialized_copy(wlIter.first, wlIter.second, avs);
	////QueryResult qr();
	shared_ptr<pair<string, set<size_t>>> sp = make_shared<pair<string,set<size_t>>>(*wlIter);
	QueryResult qrfound(spVs, sp);
	return qrfound;
}


#endif // !TextQuery_H
