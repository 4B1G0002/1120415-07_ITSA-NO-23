// 1120415-07_ITSA NO-23.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
// ITSA 40題基礎題 題目23. 找零錢問題

#include<iostream>
#include<sstream>
using namespace std;
int main() {
	string input, str;
	int mon[4];

	getline(cin, input);
	istringstream cut(input);
	for (int i = 0; i < 4; i++)//逐一拆字讀入陣列 
	{
		getline(cut, str, ',');
		istringstream sa(str);
		sa >> mon[i];
	}
	if (mon[0] > mon[1] * 15 + mon[2] * 20 + mon[3] * 30)//判定零錢是否足夠,同時重複利用陣列空間 
	{
		mon[0] = mon[0] - mon[1] * 15 - mon[2] * 20 - mon[3] * 30;//結算剩餘金額 
		mon[2] = mon[0] / 50; mon[0] %= 50;
		mon[1] = mon[0] / 5; mon[0] %= 5;
		cout << mon[0] << "," << mon[1] << "," << mon[2] << endl; return 0;
	}
	else cout << "0" << endl; return 0;//金額不足 
}