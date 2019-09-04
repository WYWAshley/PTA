#include<iostream>
#include<string>
using namespace std;

int Q1050()
{
	string s1, s2;
	bool flag[256] = { false };
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size(); i++) {
		flag[s2[i]] = true;
	}
	for (int i = 0; i < s1.size(); i++) {
		if (!flag[s1[i]])
			cout << s1[i];
	}

	system("pause");
	return 0;
}