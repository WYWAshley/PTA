#include<iostream>
#include<string>
#include<map>
using namespace std;

int Q1071()
{
	map<string, int> m;
	string str, tmp;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (isalnum(str[i])) {
			tmp += tolower(str[i]);
		}
		if (!isalnum(str[i]) || i == str.length() - 1){
			if (tmp.length() > 0)
				m[tmp]++;
			tmp.clear();
		}
	}
	int max = -1;
	string maxword = "";
	for (auto it = m.begin(); it != m.end(); it++) {
		if (max < it->second || max == it->second && maxword < it->first) {
			max = it->second;
			maxword = it->first;
		}
	}
	printf("%s %d", maxword.c_str(), max);
	system("pause");
	return 0;
}