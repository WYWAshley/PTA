#include<iostream>
#include<vector>
using namespace std;
#define INF 99999
int start, des, mincost = INF;
vector<vector<int>> road;
vector<vector<int>> cost;
vector<vector<int>> pre;//��ŵ�ÿ���ڵ������ǰһ���ڵ�
vector<int> dis;//��Ŵ�start��ÿ���ڵ����̾���
vector<bool> visit;
vector<int> path, tmppath;//���·��
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
		for (int i = 0; i < citinum; i++) {//�ҵ���С������û�б�visit�ĵ�
			if (visit[i] == false && dis[i] < min) {
				u = i;
				min = dis[i];
			}
		}
		if (u == -1) //ȫ��visitһ����
			break;
		visit[u] = true;
		for (int i = 0; i < citinum; i++) {//����������ܵ�������е㣬�ɳھ���
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
	//������
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << dis[des] << " " << mincost;
	system("pause");
	return 0;
}