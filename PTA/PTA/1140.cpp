#include<iostream>
#include<string>
using namespace std;

int Q1141()
{
	string s, res;
	int cnt, i = 1;
	cin >> s >> cnt;
	while (i++ < cnt) {
		char c = s[0];
		int count = 1;
		for (int ii = 1; ii < s.size(); ii++) {
			char temp = s[ii];
			if (temp == c) {
				count++;
			}
			else {
				res += c;
				res += count + '0';
				count = 1;
				c = temp;
			}
		}
		//ע������ѭ��֮��Ҫ�����һ�δ洢�Ķ�����������
		res += c;
		res += count + '0';
		s = res;
		res = "";
	}
	cout << s;
	system("pause");
	return 0;
}