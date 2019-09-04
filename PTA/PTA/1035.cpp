#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct str {
	string a;
	string p;
};
int Q1035()
{
	int num;
	vector<str> v;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		string acc, pass;
		acc.resize(11);
		pass.resize(11);
		scanf("%s %s",&acc[0], &pass[0]);
		bool flag = 0;
		for (int j = 0; j < pass.size(); j++) {
			if (pass[j] == '1') {
				pass[j] = '@';
				flag = 1;
			}
			if (pass[j] == '0') {
				pass[j] = '%';
				flag = 1;
			}
			if (pass[j] == 'l') {
				pass[j] = 'L';
				flag = 1;
			}
			if (pass[j] == 'O') {
				pass[j] = 'o';
				flag = 1;
			}
		}
		if (flag == 1) {
			str s;
			s.a = acc;
			s.p = pass;
			v.push_back(s);
		}
	}
	if (v.size() == 0) {
		if (num == 1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n", num);
	}
	else {
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++) {
			printf("%s %s\n", v[i].a.c_str(), v[i].p.c_str());
		}
	}
	system("pause");
	return 0;
}