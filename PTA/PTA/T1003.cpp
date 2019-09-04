#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#define MAXN 500
#define INF 999999
using namespace std;

int cap[MAXN][MAXN], flow[MAXN][MAXN];
int pre[MAXN], res[MAXN];
int Edmonds_Karp(int start, int end)
{
	int maxflow = 0;
	memset(flow, 0, sizeof(flow));
	memset(pre, 0, sizeof(pre));
	queue<int> q;
	while (true)
	{
		memset(res, 0, sizeof(res));
		res[start] = INF;
		q.push(start);
		while (!q.empty()) //BFS寻找增广路
		{
			int u = q.front();
			q.pop();
			for (int v = 1; v <= end; v++)
				if (!res[v] && cap[u][v]>flow[u][v])
				{
					res[v] = min(res[u], cap[u][v] - flow[u][v]);//start-v路径上的最小残量
					pre[v] = u;//记录v的父亲，并加入队列中
					q.push(v);
				}
		}
		for (int u = end; u != start; u = pre[u])//从汇点往回走
		{
			flow[pre[u]][u] += res[end];//更新正向流
			flow[u][pre[u]] -= res[end];//更新反向流
		}
		maxflow += res[end]; //更新从s流出的总流量
		if (res[end] == 0) return maxflow;//无法继续更新最大流量，则当前流已经是最大流
	}
}
int T1003() 
{
	map<string, int> id;
	map<int, string> name;
	string start, end;
	int transNum, counter = 1;
	cin >> start >> end >> transNum;
	id[start] = 0;
	name[0] = start;
	for (int i = 0; i < transNum; i++) {
		string tmp1, tmp2;
		int tmpcap;
		cin >> tmp1 >> tmp2 >> tmpcap;
		if (id.find(tmp1) == id.end()) {
			id[tmp1] = counter;
			name[counter] = tmp1;
			counter++;
		}
		if (id.find(tmp2) == id.end()) {
			id[tmp2] = counter;
			name[counter] = tmp2;
			counter++;
		}
		cap[id[tmp1]][id[tmp2]] = tmpcap;
	}
	id[end] = counter;
	name[counter] = end;
	
	cout << Edmonds_Karp(0, counter) << endl;
	system("pause");
	return 0;
}