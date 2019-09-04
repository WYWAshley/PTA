#include<iostream>
#include<string>
using namespace std;
string num[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string wei[5] = {"","","Shi","Bai","Qian"};
string res = " ";
void read(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			int j = i;
			while (j < s.size() && s[j] == '0')  j++;
			if (j == s.size())
				return;
			else
				i = j - 1;
		}
		if (res.back() != ' ') res += " ";
		res += num[s[i] - '0'];
		if (i != s.size() - 1 && s[i] != '0') {
			if (res.back() != ' ') res += " ";
			res += wei[s.size() - i];
		}
	}
}
int Q1082()
{
	string str;
	getline(cin, str);
	if (str[0] == '-') {
		printf("Fu ");
		str.erase(0,1);
	}
	string tmp1, tmp2, tmp3;
	if (str.size() > 8) {
		tmp1 = str.substr(0, str.size() - 8);
		read(tmp1);
		res += " Yi";
		str.erase(0, str.size() - 8);
	}
	if (str.size() > 4) {
		tmp2 = str.substr(0, str.size() - 4);
		if (stoi(tmp2) != 0) {
			read(tmp2);
			res += " Wan";
			str.erase(0, str.size() - 4);
		}
		else {
			if (res.back() != ' ') res += " ";
			res += "ling";
		}
	}
	tmp3 = str;
	if (stoi(tmp3) != 0)
		read(tmp3);
	else {
		if (res.back() != ' ') res += " ";
		res += "ling";
	}
	res.erase(0, 1);
	printf("%s", res.c_str());
	system("pause");
	return 0;
}