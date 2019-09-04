#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 501;
int road[SIZE][SIZE];
struct Node {
	Node() {
		num = 0;
		dis = -1;
		visited = false;
	}
	int num;
	unsigned int dis;
	bool visited;
};
Node stations[SIZE];
vector <int> v;
vector <int> s;
int cursend = 0;
int curback = 0;
unsigned int minsend = -1, minback = -1, lastdis = -1;
int cap, nodenum, des;

void findpath(int cur, int dis, vector<int > &v) {
	if (dis > lastdis)
		return;
	if (cur == des) {
		bool flag = false;
		if (dis < lastdis)
			flag = true;
		else if (dis == lastdis)
			if (cursend < minsend || cursend == minsend && curback < minback)
				flag = true;
		if (flag) {
			lastdis = dis;
			minsend = cursend;
			minback = curback;
			s = v;
		}
		return;
	}
	for (int j = 1; j <= nodenum; j++) {
		if (road[cur][j] && !stations[j].visited) {
			stations[j].visited = true;
			int lastsend = cursend, lastback = curback;
			v.push_back(j);
			if (stations[j].num + curback < cap / 2) {
				cursend += cap / 2 - (stations[j].num + curback);
				curback = 0;
			}
			else
				curback = stations[j].num + curback - cap / 2;
			findpath(j, dis + road[cur][j], v);
			cursend = lastsend;
			curback = lastback;
			stations[j].visited = false;
			v.pop_back();
		}
	}
}
int Q1018()
{
	int M;
	scanf("%d%d%d%d", &cap, &nodenum, &des, &M);
	for (int i = 1; i <= nodenum; i++) {
		scanf("%d", &stations[i].num);
	}
	for (int i = 0; i <= nodenum; i++)
		for (int j = 0; j <= nodenum; j++) {
			road[i][j] = 0;
			road[j][i] = 0;
		}
	for (int i = 0; i<M; i++) {
		int c1, c2, t;
		scanf("%d%d%d", &c1, &c2, &t);
		road[c1][c2] = t;
		road[c2][c1] = t;
	}
	findpath(0, 0, v);
	printf("%d 0", minsend);
	vector <int>::iterator iter = s.begin();
	while (iter != s.end()) {
		printf("->%d", *iter);
		iter++;
	}
	printf(" %d\n", minback);
	system("pause");
	return 0;
}
