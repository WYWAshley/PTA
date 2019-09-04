#include<iostream>
#include<vector>
using namespace std;

int cnt = 0;
void DFS(int node, vector<vector<int>> &edge, vector<bool> &isMarked) {
	isMarked[node] = 1;
	cnt++;
	for (int i = 0; i < edge[node].size(); i++) {
		if (!isMarked[edge[node][i]])
			DFS(edge[node][i], edge, isMarked);
	}
}
int Q1126()//要考虑连通图的前提，先深度遍历一遍
{
	int nodeNum, edgeNum;
	scanf("%d %d", &nodeNum, &edgeNum);
	vector<vector<int>> edge(nodeNum+1);
	for (int i = 0; i < edgeNum; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		edge[n1].push_back(n2);
		edge[n2].push_back(n1);
	}
	int even = 0, odd = 0;
	vector<bool> isMarked(nodeNum+1, false);
	DFS(1, edge, isMarked);
	bool flag = 0;
	if (cnt == nodeNum)
		flag = 1;
	for (int i = 1; i <= nodeNum; i++) {
		if (i != 1)
			printf(" ");
		printf("%d", edge[i].size());
		if (edge[i].size() % 2 == 0)
			even++;
		else
			odd++;
	}
	printf("\n");
	if (flag && odd == 0)
		printf("Eulerian");
	else if (flag && odd == 2)
		printf("Semi-Eulerian");
	else
		printf("Non-Eulerian");
	system("pause");
	return 0;
}