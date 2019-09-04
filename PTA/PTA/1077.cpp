#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int Q1077()
{
	int num;
	scanf("%d\n", &num);//注意这里需要加一个\n，否则读取不了下一个string
	string res;
	getline(cin, res);
	for (int i = 1; i < num; i++) {
		string s;
		getline(cin, s);
		int j, k;
		bool flag = 0;
		for (j = s.size() - 1, k = res.size() - 1; j >= 0, k >= 0; j--, k--) {
			if (s[j] != res[k]) {
				flag = 1;
				break;
			}
		}
		if(flag)
			res = res.substr(k + 1);
	}
	if (res.size() == 0)
		printf("nai");
	else
		printf("%s", res.c_str());

	system("pause");
	return 0;
}