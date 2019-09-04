#include<iostream>
#include<vector>
using namespace std;

int Q1041()
{
	int a[10010] = { 0 };
	int num;
	vector<int> v;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int d;
		scanf("%d", &d);
		v.push_back(d);
		a[d]++;
	}
	bool flag = 0;
	for (int i = 0; i < v.size(); i++) {
		if (a[v[i]] == 1) {
			cout << v[i];
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "None";
	system("pause");
	return 0;
}