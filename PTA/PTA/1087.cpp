#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stack>
#define INF 999999
using namespace std;

int mincost = INF, maxhapp = 0, cnt = 1;
int num_city, num_route;
stack<int> res, tmp;
vector<int> happ;
vector<vector<int>> road;
vector<bool> flag;
map<string, int> id;
map<int, string> name;

void DFS(int start, int cost, int happy) {
	flag[start] = true;
	tmp.push(start);
	if (cost > mincost)
		return;
	if (start == id["ROM"]) {
		if (cost < mincost) cnt = 1;
		else if(cost == mincost) cnt++;
		if (cost < mincost || cost == mincost && happy > maxhapp
			|| cost == mincost && happy == maxhapp && res.size() > tmp.size()) {
			res = tmp;
			mincost = cost;
			maxhapp = happy;
		}
		return;
	}
	for (int i = 0; i < num_city; i++) {
		if (!flag[i] && road[start][i] != INF) {
			DFS(i, cost + road[start][i], happy + happ[i]);
			if (!tmp.empty()) {
				flag[tmp.top()] = 0;
				tmp.pop();
			}
		}
	}
}
int Q1087()
{
	cin >> num_city >> num_route;
	road.resize(num_city);
	happ.resize(num_city);
	flag.resize(num_city, false);
	for (int i = 0; i < num_city; i++)
		road[i].resize(num_city, INF);
	string first;
	cin >> first;
	id[first] = 0;
	name[0] = first;
	happ[0] = 0;
	for (int i = 1; i < num_city; i++) {
		string na;
		cin >> na;
		id[na] = i;
		name[i] = na;
		scanf("%d", &happ[i]);
	}
	for (int i = 0; i < num_route; i++) {
		string n1, n2;
		int d;
		cin >> n1 >> n2 >> d;
		road[id[n1]][id[n2]] = road[id[n2]][id[n1]] = d;
	}
	DFS(0, 0, 0);
	printf("%d %d %d %d\n", cnt, mincost, maxhapp, (int)(maxhapp/(res.size()-1)));
	printf("%s", first.c_str());
	stack<int> rever;
	while (res.size() > 1) {
		rever.push(res.top());
		res.pop();
	}
	while (!rever.empty()) {
		printf("->%s", name[rever.top()].c_str());
		rever.pop();
	}
	system("pause");
	return 0;
}