﻿// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
#include<iterator>
#include<map>
#include<unordered_map>
using namespace std;
int main() {
	using um = unordered_map<string, size_t>;
	unordered_map<string, size_t>unor_m;
	istream_iterator<string>in(cin), end;
	while (in != end) {
		++unor_m[*in++];
	}
	cout << "bucket_count(): " << unor_m.bucket_count() << endl;
	cout << "max_bucket_count() : " << unor_m.max_bucket_count() << endl;
	for (size_t n = 0; n < unor_m.bucket_count(); n++)
	{
		cout << "bucket_size(" << n << "):" << unor_m.bucket_size(n) << endl;
		if (unor_m.bucket_size(n) > 0) {
			um::const_local_iterator mFactor = unor_m.cbegin(n);
			while (mFactor !=
				unor_m.cend(n))
			{
				cout << mFactor->first << ":" << mFactor->second << endl;
				++mFactor;
			}
		}
	}

	size_t bn = unor_m.bucket("孫守真");
	um::local_iterator bi = unor_m.begin(bn);
	while (bi != unor_m.end(unor_m.bucket("孫守真")))
	{
		cout << bi->first << ":" << bi->second << ",";
		bi++;
	}
	cout << endl;

}

//int main(int argc, const char** argv)
//{
//	return 0;
//}


			//printf("%i\n", i);
			//std::cout << "Hello World!\n";



// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
