#include<iostream>
#include<string>
using namespace std;

int Q1031()
{
	int n, h, w, cnt = 0;
	string s;
	cin >> s;
	n = s.length();
	h = (n + 2) / 3;
	w = n - 2 * h;
	for (int i = 0; i < h; i++) {
		if (i < h - 1) {
			cout << s[cnt];
			for (int j = 0; j < w; j++)
				cout << " ";
			cout << s[n - 1 - cnt] << endl;
			cnt++;
		}
		else {
			for (int j = 0; j <= 1 + w; j++)
				cout << s[cnt + j];
		}
	}
	system("pause");
	return 0;
}
