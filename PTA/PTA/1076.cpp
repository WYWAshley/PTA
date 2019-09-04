#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int num_user, num_level;
vector<bool> flag;
vector<vector<int>> follow;
int cnt;
struct person
{
	int id, level;
};
queue<person> q;
void bfs()
{
	while (!q.empty()) {
		person root = q.front();
		q.pop();
		if (root.level < num_level) {
			for (int i = 0; i < follow[root.id].size(); i++) {
				if (!flag[follow[root.id][i]]) {
					person p;
					p.id = follow[root.id][i];
					p.level = root.level + 1;
					q.push(p);
					flag[p.id] = 1;
					cnt++;
				}
			}
		}
	}
}
int Q1076()
{
	scanf("%d %d", &num_user, &num_level);
	follow.resize(num_user + 1);
	flag.resize(num_user + 1, false);
	for (int i = 1; i <= num_user; i++) {
		int t;
		scanf("%d", &t);
		for (int j = 0; j < t; j++) {
			int k;
			scanf("%d", &k);
			follow[k].push_back(i);
		}
	}
	int q_num;
	scanf("%d", &q_num);
	for (int i = 0; i < q_num; i++) {
		int user;
		cnt = 0;
		fill(flag.begin(), flag.end(), false);
		while (!q.empty())
			q.pop();
		scanf("%d", &user);
		person root;
		root.id = user;
		root.level = 0;
		q.push(root);
		flag[root.id] = 1;
		bfs();
		printf("%d\n", cnt);
	}
	system("pause");
	return 0;
}