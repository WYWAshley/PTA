#include<iostream>
#include<string>
using namespace std;

string str;
int res = 0;
int m = 0;

int findsame(int end, char c)//´ÓºóÍùÇ°ÕÒ
{
	for (int i = end -1 ; i >= 0; i--) {
		if (str[i] == c)
			return i;
	}
	return -1;
}
int Q1040()
{
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		int k = findsame(str.length(), ch);
		while (k > i) {
			for (int j = 0; i + j <= k - j; j++) {
				if (str[i + j] == str[k - j]) {
					if (i + j < k - j) res += 2;
					else if (i + j == k - j) res += 1;
				}
				else {
					res = 0;
					break;
				}
			}
			k = findsame(k, ch);
			if (m < res)
				m = res;
			res = 0;
		}
	}
	cout << (m > 1 ? m : 1);
	system("pause");
	return 0;
} 