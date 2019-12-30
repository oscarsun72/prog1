﻿// prog1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

//using std::cout; using std::cin;using std::endl;
//#include<cassert>//前置處理器（preprocessor）偵錯、斷言（assert）

#include<iostream>
using namespace std;
struct destination {};	// represents what we are connecting to
struct connection {};           // information needed to use the connection
connection connect(destination*) { connection c; return c; } // open the connection
void disconnect(connection) { ; }      // close the given connection
//寫出一個你自己版本的函式，用shared_ptr來管理connection。
//void end_connection(connection* p) { disconnect(*p); }//課本用普通指標
void end_connection(shared_ptr<connection>& p) { disconnect(*p.get()); }//我們用智慧指標
//void f(destination & d /* other parameters */)
//	{
//		// get a connection; must remember to close it when done
//		connection c = connect(&d);
//		// use the connection
//		// if we forget to call disconnect before exiting f, there will be no way to close c
//	}
void f(destination& d /* other parameters */)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c);
	end_connection(p);
	// use the connection
	// when f exits, even if by an exception, the connection will be properly closed
}
int main() {
	destination d;
	f(d);
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
