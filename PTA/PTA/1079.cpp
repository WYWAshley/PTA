#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<int> layer;
vector<vector<int>> follow;
void DFS(int root, int level)
{
	if (layer[root] == -1)
		layer[root] = level;
	else
		layer[root] = min(level, layer[root]);
	for (int i = 0; i < follow[root].size(); i++) {
		DFS(follow[root][i], level + 1);
	}
	return;
}
int Q1079()
{
	int num;
	double cost, profit;
	scanf("%d %lf %lf", &num, &cost, &profit);
	follow.resize(num);
	layer.resize(num, -1);
	vector<int> id, amount;
	for (int i = 0; i < num; i++) {
		int count;
		scanf("%d", &count);
		if (count == 0) {
			int tmp;
			scanf("%d", &tmp);
			id.push_back(i);
			amount.push_back(tmp);
			continue;
		}
		for (int j = 0; j < count; j++) {
			int d;
			scanf("%d", &d);
			follow[i].push_back(d);
		}
	}
	DFS(0, 0);
	double res = 0;
	for (int i = 0; i < id.size(); i++) {
		res += amount[i] * pow((profit * 0.01 + 1), layer[id[i]]);
	}
	printf("%.1f", res * cost);
	system("pause");
	return 0;
}