#include<iostream>
#include<string>
using namespace std;
int Q1073()
{
	string str, res, tmp;
	getline(cin, str);
	if (str[0] == '-')
		res += "-";
	str.erase(0,1);
	int cnt = -1;
	while (str[++cnt] != 'E') {
		if (str[cnt] == '.')
			continue;
		tmp += str[cnt];
	}
	str = str.substr(cnt+1);
	if (str[0] == '-') {
		str.erase(0, 1);
		int t = stoi(str);
		res += "0.";
		for (int i = 0; i < t - 1; i++)
			res += "0";
		res += tmp;
	}
	else {
		str.erase(0, 1);
		int t = stoi(str) - tmp.size() + 1;
		res += tmp;
		if (t >= 0) {
			for (int i = 0; i < t; i++)
				res += "0";
		}
		else {
			res.insert(res.size() + t, ".");
		}
	}
	printf("%s\n", res.c_str());
	system("pause");
	return 0;
}