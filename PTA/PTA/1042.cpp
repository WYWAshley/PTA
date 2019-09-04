#include<iostream>
#include<string>
#include<vector>
using namespace std;

char shape[5] = {'S', 'H', 'C', 'D', 'J'};
string num[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
int Q1042()
{
	string a[5][13];
	vector<string> ini(55);
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 13; j++) {
			a[i][j] += shape[i];
			a[i][j] += num[j];
			cnt++;
			ini[cnt] = a[i][j];
			if (cnt == 54)
				break;
		}
	}
	int repeat;
	scanf("%d", &repeat);
	int trans[55];
	for (int i = 1; i <= 54; i++) {
		scanf("%d", &trans[i]);
	}
	for (int i = 0; i < repeat; i++) {
		vector<string> v(55);
		for (int j = 1; j <= 54; j++) {
			v[trans[j]] = ini[j];
		}
		ini = v;
	}
	cout << ini[1];
	for (int i = 2; i <= 54; i++) {
		cout << " " << ini[i];
	}
	system("pause");
	return 0;
}