#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int Q1142()
{
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	vector<vector<int>> edge(nV + 1);
	for (int i = 0; i<nE; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int qnum;
	scanf("%d", &qnum);
	for (int i = 0; i<qnum; i++) {
		int tnum;
		scanf("%d", &tnum);
		bool flag = true;
		vector<int> temp(nV + 1, 0);
		vector<bool> temp2(nV + 1, false);
		for (int j = 0; j<tnum; j++) {
			int now;
			scanf("%d", &now);
			temp2[now] = true;
			for (int k = 0; k<edge[now].size(); k++) {
				temp[edge[now][k]]++;
			}
		}
		for (int j = 1; j<nV + 1; j++) {//检查是不是clique
			if (temp2[j] && temp[j] < tnum - 1) {
				printf("Not a Clique\n");
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		for (int j = 1; j<nV + 1; j++) {//检查是不是maximal
			if (!temp2[j] && temp[j] == tnum) {
				printf("Not Maximal\n");
				flag = false;
				break;
			}
		}
		if (flag)
			printf("Yes\n");
	}
	system("pause");
	return 0;
}
