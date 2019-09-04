#include<vector>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

bool isPalindromic(string &str) {
	int l = str.length() - 1;
	for (int i = 0; i <= l / 2; i++) {//这里是小于等于
		if (str[i] != str[l - i])
			return false;
	}
	return true;
}
string add(string &oldstr, string &str) {
	int l = str.length();
	bool flag = false;
	string res;
	for (int i = l - 1; i >= 0; i--) {
		int num = (str[i] - '0') + (oldstr[i] - '0');
		if (flag) {
			num++;
			flag = !flag;
		}
		if (num >= 10) {
			num = num - 10;
			flag = true;
		}
		res += (num + '0');
	}
	if (flag)
		res += '1';
	reverse(res.begin(), res.end());

	if (str[0] == '0')//注意这里要把首位为0的去掉
		str.erase(0, 1);

	return res;
}
int Q1136()
{
	string str;
	getline(cin, str);

	int i = 0;
	string newstr = str, oldstr = str;
	for (i; i < 10 && !isPalindromic(str); i++) {
		oldstr = str;
		reverse(str.begin(), str.end());
		newstr = add(oldstr, str);
		printf("%s + %s = %s\n",oldstr.c_str(), str.c_str(), newstr.c_str());
		str = newstr;
	}
	if (i == 10)
		printf("Not found in 10 iterations.\n");
	else
		printf("%s is a palindromic number.\n", newstr.c_str());
	system("pause");
	return 0;
}