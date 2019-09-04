#include<iostream>
#include<vector>
using namespace std;
#define INF 99999
int start, des, mincost = INF;
vector<vector<int>> road;
vector<vector<int>> cost;
vector<vector<int>> pre;//存放到每个节点最近的前一个节点
vector<int> dis;//存放从start到每个节点的最短距离
vector<bool> visit;
vector<int> path, tmppath;//存放路径
void DFS(int v)
{
	tmppath.push_back(v);
	if (v == start) {
		int tmpcost = 0;
		for (int i = tmppath.size() - 1; i >= 1; i--) {
			tmpcost += cost[tmppath[i]][tmppath[i - 1]];
		}
		if (tmpcost < mincost) {
			mincost = tmpcost;
			path = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tmppath.pop_back();
	return;
}
int Q1030()
{
	int citinum, roadnum;
	cin >> citinum >> roadnum >> start >> des;
	dis.resize(citinum, INF);
	visit.resize(citinum, false);
	road.resize(citinum);
	cost.resize(citinum);
	for (int i = 0; i < citinum; i++) {
		road[i].resize(citinum, INF);
		cost[i].resize(citinum, INF);
	}
	pre.resize(citinum);
	for (int i = 0; i < roadnum; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		road[a][b] = c; road[b][a] = c;
		cost[a][b] = d; cost[b][a] = d;
	}
	//Dijksta
	dis[start] = 0;
	for (int i = 0; i < citinum; i++) {
		int u = -1, min = INF;
		for (int i = 0; i < citinum; i++) {//找到最小距离且没有被visit的点
			if (visit[i] == false && dis[i] < min) {
				u = i;
				min = dis[i];
			}
		}
		if (u == -1) //全部visit一遍了
			break;
		visit[u] = true;
		for (int i = 0; i < citinum; i++) {//遍历这个点能到达的所有点，松弛距离
			if (visit[i] == false && road[u][i] != INF) {
				if (road[u][i] + dis[u] < dis[i]) {
					dis[i] = road[u][i] + dis[u];
					pre[i].clear();
					pre[i].push_back(u);
				}
				else if (road[u][i] + dis[u] == dis[i]) {
					pre[i].push_back(u);
				}
			}
		}
	}
	DFS(des);
	//输出结果
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << dis[des] << " " << mincost;
	system("pause");
	return 0;
}