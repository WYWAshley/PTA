#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<bool> vis;
int num_h, num_g, num_r, range, inf;
int shortest, total; // 存储一个加油站到屋子的最短距离和平均距离
vector<vector<int> > road;
vector<vector<int> > dis;
bool dijkstra(int start)
{
	for (int k = 1; k < num_h + num_g; k++) {
		int mindis = inf + 1, minnode;
		for (int i = 1; i < num_h + num_g + 1; i++) {
			if (!vis[i] && mindis > dis[start][i]) {
				mindis = dis[start][i];
				minnode = i;
			}
		}
		if (minnode <= num_h) {
			if (mindis == inf) // 说明这个点存在到不了的house，直接返回
				return false;
			if (shortest > mindis)
				shortest = mindis;
			total += mindis;
		}
		// 因为是从1开始循环的，说明前面的num_h都已经搞定，那就直接返回吧
		if (minnode > num_h && mindis == inf)
			return true;
		vis[minnode] = 1; //已找到最短路径
		for (int i = 1; i < num_h + num_g + 1; i++) {
			if (!vis[i] && dis[start][i] > dis[start][minnode] + road[minnode][i])
				dis[start][i] = dis[i][start] = dis[start][minnode] + road[minnode][i];
		}
	}
	return true;
}

int Q1072()
{
	int minstation = -1;
	scanf("%d%d%d%d", &num_h, &num_g, &num_r, &range);
	inf = range + 1;
	double minaverage = inf, minshortest = -1;
	road.resize(num_h + num_g + 1);
	dis.resize(num_h + num_g + 1);
	for (int i = 1; i < num_h + num_g + 1; i++) {
		road[i].resize(num_h + num_g + 1, inf);
		dis[i].resize(num_h + num_g + 1, inf);
	}
	vis.resize(num_h + num_g + 1, 0);
	for (int i = 0; i < num_r; i++) {
		string s1, s2;
		int len, d1 = -1, d2 = -1;
		cin >> s1 >> s2 >> len;
		if (len >= inf)
			continue;
		if (s1[0] == 'G') {
			s1.erase(0, 1);
			d1 = num_h + stoi(s1);
		}
		else {
			d1 = stoi(s1);
		}
		if (s2[0] == 'G') {
			s2.erase(0, 1);
			d2 = num_h + stoi(s2);
		}
		else {
			d2 = stoi(s2);
		}
		road[d1][d2] = len;
		road[d2][d1] = len;
		dis[d1][d2] = len;
		dis[d2][d1] = len;
	}
	for (int i = num_h + 1; i < num_g + num_h + 1; i++) {
		fill(vis.begin(), vis.end(), 0);
		total = 0;
		shortest = inf;
		vis[i] = 1;
		if (dijkstra(i)) { //如果返回的是true，计算他的平均路程
			double average = total * 1.0 / num_h;
			if (minshortest < shortest) {
				minaverage = average;
				minshortest = shortest;
				minstation = i;
			}
			else if (minshortest == shortest) {
				if (minaverage > average) {
					minaverage = average;
					minshortest = shortest;
					minstation = i;
				}
			}
		}
	}
	if (minaverage == inf) {
		printf("No Solution\n");
		return 0;
	}
	printf("G%d\n", minstation - num_h);
	printf("%.1f %.1f\n", minshortest, minaverage);
	return 0;
}