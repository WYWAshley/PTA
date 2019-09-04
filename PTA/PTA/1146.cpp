#include<iostream>
#include<vector>
#include<string>
using namespace std;

int Q1146()
{
	int nodeNum, edgeNum;
	cin >> nodeNum >> edgeNum;
	vector<int> degree(nodeNum+1, 0);
	vector<vector<int>> edge(nodeNum+1);
	for (int i = 0; i < edgeNum; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		edge[n1].push_back(n2);
		degree[n2]++;
	}
	int qNum;
	cin >> qNum;
	vector<int> ans;
	for (int i = 0; i < qNum; i++) {
		vector<int> dd = degree;
		for (int j = 0; j < nodeNum; j++) {
			int now;
			cin >> now;
			if (dd[now] != 0) {
				string str;
				getline(cin, str);
				ans.push_back(i);
				break;
			}
			else {
				for (int k = 0; k < edge[now].size(); k++) {
					dd[edge[now][k]]--;
				}
			}
		}
	}
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); i++) {
		printf(" %d", ans[i]);
	}
	system("pause");
	return 0;
}