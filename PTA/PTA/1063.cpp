#include<iostream>
#include<set>
#include<vector>
using namespace std;

int Q1063()
{
	int setNum;
	cin >> setNum;
	vector<set<int>> v(setNum + 1);
	for (int i = 1; i < setNum + 1; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int d;
			scanf("%d", &d);
			v[i].insert(d);
		}
	}
	int qnum;
	scanf("%d", &qnum);
	for (int i = 0; i < qnum; i++) {
		int n1, n2, ct = 0, nt = 0;
		cin >> n1 >> n2;
		for (auto it = v[n2].begin(); it != v[n2].end(); it++){
			if (v[n1].find(*it) == v[n1].end()) //刚开始用两个set合并会超时，这说明对于set查找比插入更快
				nt++;
			else
				ct++;
		}
		double res = ct * 1.0 / (v[n1].size() + nt);
		printf("%.1f%%\n", res * 100);
	}
	system("pause");
	return 0;
}