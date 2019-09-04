#include<iostream>
#include<vector>
#include<string>
#define INF 999999999
using namespace std;

struct fare {
	int next, t, l;
};
vector<vector<struct fare>> vf;
vector<int> prenode, cost, cnt;
vector<bool> isChecked;
int nodeNum, edgeNum;
void dijkstra_dis(int &start, int &end, int &nodenum) {
	cost[start] = 0, cnt[start] = 0, isChecked[start] = 1;
	for (int i = 0; i < vf[start].size(); i++) {
		cost[vf[start][i].next] = vf[start][i].l;
		prenode[vf[start][i].next] = start;
		cnt[vf[start][i].next] = vf[start][i].t;
	}
	for (int k = 0; k < nodenum - 1; k++) {
		int mincost = INF, minnode;
		for (int i = 0; i < nodenum; i++) {
			if (!isChecked[i] && cost[i] < mincost) {
				minnode = i;
				mincost = cost[i];
			}
		}
		isChecked[minnode] = 1;
		for (int i = 0; i < vf[minnode].size(); i++) {
			int nextnode = vf[minnode][i].next;
			if (cost[nextnode] > cost[minnode] + vf[minnode][i].l
				|| cost[nextnode] == cost[minnode] + vf[minnode][i].l
				&& cnt[nextnode] > vf[minnode][i].t + cnt[minnode]) {
				prenode[nextnode] = minnode;
				cost[nextnode] = cost[minnode] + vf[minnode][i].l;
				cnt[nextnode] = vf[minnode][i].t + cnt[minnode];
			}
		}
	}
}
void dijkstra_time(int &start, int &end, int &nodenum) {
	fill(cost.begin(), cost.end(), INF);
	fill(prenode.begin(), prenode.end(), INF);
	fill(cnt.begin(), cnt.end(), INF);
	fill(isChecked.begin(), isChecked.end(), false);
	cost[start] = 0, cnt[start] = 0, isChecked[start] = 1;
	for (int i = 0; i < vf[start].size(); i++) {
		cost[vf[start][i].next] = vf[start][i].t;
		prenode[vf[start][i].next] = start;
		cnt[vf[start][i].next] = 1;
	}
	for (int k = 0; k < nodenum - 1; k++) {
		int mincost = INF, minnode;
		for (int i = 0; i < nodenum; i++) {
			if (!isChecked[i] && cost[i] < mincost) {
				minnode = i;
				mincost = cost[i];
			}
		}
		isChecked[minnode] = 1;
		for (int i = 0; i < vf[minnode].size(); i++) {
			int nextnode = vf[minnode][i].next;
			if (cost[nextnode] > cost[minnode] + vf[minnode][i].t
				|| cost[nextnode] == cost[minnode] + vf[minnode][i].t
				&& cnt[nextnode] > cnt[minnode] + 1) {
				prenode[nextnode] = minnode;
				cost[nextnode] = cost[minnode] + vf[minnode][i].t;
				cnt[nextnode] = cnt[minnode] + 1;
			}
		}
	}
}
int Q1111()
{
	scanf("%d %d", &nodeNum, &edgeNum);
	vf.resize(nodeNum);
	prenode.resize(nodeNum, INF);
	cost.resize(nodeNum, INF);
	cnt.resize(nodeNum, INF);
	isChecked.resize(nodeNum, false);
	for (int i = 0; i < edgeNum; i++) {
		int V1, V2, oneway, length, time;
		cin >> V1 >> V2 >> oneway >> length >> time;
		fare f;
		f.next = V2; f.l = length, f.t = time;
		vf[V1].push_back(f);
		if (oneway == 0) {
			f.next = V1;
			vf[V2].push_back(f);
		}
	}
	int source, end;
	cin >> source >> end;
	dijkstra_dis(source, end, nodeNum);
	int distance = cost[end];
	string ans_dis;
	ans_dis += to_string(source);
	vector<int> tmp;
	int j = end;
	while (j != source) {
		tmp.push_back(j);
		j = prenode[j];
	}
	for (int i = tmp.size() - 1; i >= 0; i--) {
		ans_dis += " -> ";
		ans_dis += to_string(tmp[i]);
	}
	//cout << ans_dis;
	dijkstra_time(source, end, nodeNum);
	string ans_time;
	ans_time += to_string(source);
	tmp.clear();
	j = end;
	while (j != source) {
		tmp.push_back(j);
		j = prenode[j];
	}
	for (int i = tmp.size() - 1; i >= 0; i--) {
		ans_time += " -> ";
		ans_time += to_string(tmp[i]);
	}
	//cout << ans_time;
	if (ans_dis == ans_time) {
		printf("Distance = %d; Time = %d: ", distance, cost[end]);
		printf("%s", ans_dis.c_str());
	}
	else {
		printf("Distance = %d: ", distance);
		printf("%s\n", ans_dis.c_str());
		printf("Time = %d: ", cost[end]);
		printf("%s\n", ans_time.c_str());
	}

	system("pause");
	return 0;
}