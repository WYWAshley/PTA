#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string s1, string s2)
{
	string tmp1 = s1 + s2, tmp2 = s2 + s1;
 	if (tmp1 < tmp2)
		return true;
	else
		return false;
}
int Q1038()
{
	int num;
	scanf("%d", &num);
	vector<string> v(num);
	for (int i = 0; i < num; i++) {
		string s;
		scanf("%s", &s[0]);
		v[i] = &s[0];
	}
	sort(v.begin(), v.end(), cmp);
	bool flag = 0;
	for (int i = 0; i < v.size(); i++) {
		int j = 0;
		if (flag == 0) {
			while (v[i][j] == '0')
				j++;
		}
		for (; v[i][j] != '\0'; j++) {
			printf("%c", v[i][j]);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("0\n");
	system("pause");
	return 0;
}