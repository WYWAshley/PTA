#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string toString(int t)
{
	string str;
	bool flag = 0;
	if (t == 0)
		return "0";
	if (t < 0) {
		t = -t;
		flag = 1;
	}
	while (t > 0) {
		str += '0' + t % 10;
		t = t / 10;
	}
	if (flag)
		str += "-";
	reverse(str.begin(), str.end());
	return str;
}
void trans(int n, string &s, string &res) {
	string rectify;
	int decimal = 0;
	bool flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (flag == 1)//过了小数点了之后开始数小数点之后的位数
			decimal++;
		if (s[i] == '.') {//遇到了小数点，之后开始计数
			flag = 1;
			continue;
		}
		else if (s[i] == '0' && rectify.empty())//存入第一个非零的数字
			continue;
		else
			rectify += s[i];
	}
	res += "0.";
	while (n > rectify.size()) {
		rectify += "0";
		decimal++;
	}
	for (int i = 0; i < n; i++) {
		res += rectify[i];
	}
	res += "*10^";
	res += toString(-decimal + rectify.size());
}
int Q1060()
{
	int n;
	string s1, s2;
	string res1, res2;
	cin >> n >> s1 >> s2;
	trans(n, s1, res1);
	trans(n, s2, res2);
	if (res1 == res2) {
		printf("YES");
		cout << " " << res1;
	}
	else {
		printf("NO");
		cout << " " << res1 << " " << res2;
	}
	system("pause");
	return 0;
}