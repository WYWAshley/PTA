#include<iostream>
#include<string>
using namespace std;

int Q1092()
{
	string str, s;
	int cnt[256] = {0}, res = 0;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
		cnt[str[i]]++;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (cnt[s[i]] > 0)
			cnt[s[i]]--;
		else
			res++;
	}
	if (res > 0)
		printf("No %d", res);
	else
		printf("Yes %d", str.length() - s.length());
	system("pause");
	return 0;
}