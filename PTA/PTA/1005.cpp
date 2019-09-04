#include<iostream>
#include<string>
#include<vector>
using namespace std;

int Q1005()
{
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.length(); i++)
	{
		res = res + s[i]-'0';
	}
	//cout << res;
	vector<string> str;
	string a[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	if (res == 0)
	{
		cout << "zero";
		return 0;
	}
	while (res > 0)
	{
		str.push_back(a[res%10]);
		res = res / 10;
	}
	cout << str[str.size() - 1];
	for (int i = str.size() - 2; i >= 0; i--)
	{
		cout <<" "<< str[i];
	}
	system("pause");
}