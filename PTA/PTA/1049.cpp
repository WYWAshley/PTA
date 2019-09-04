#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int Q1049()
{
	string str;
	cin >> str;
	int pre, post, res = 0, postcnt;
	for (int i = 0; i < str.size(); i++) {
		pre = post = postcnt = 0;
		for (int j = 0; j < i; j++) {
			pre = pre * 10 + str[j] - '0';//得到前面的数值
		}
		for (int j = i + 1; j < str.length(); j++) {
			post = post * 10 + str[j] - '0';//得到后面的数值
			postcnt++;
		}
		if (str[i] > '1')
			res = res + (pre + 1) * pow(10, postcnt);
		else if (str[i] == '1')
			res = res + pre * pow(10, postcnt) + post + 1;
		else
			res = res + pre * pow(10, postcnt);
	}
	printf("%d\n", res);
	system("pause");
	return 0;
}