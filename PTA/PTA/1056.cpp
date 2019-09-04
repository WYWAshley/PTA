#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> loser;
vector<vector<int>> allMember;
vector<int> weight;
queue<int> order;
vector<int> ranking;
int winner(vector<int> &group)
{
	int w = group[0], ww = weight[group[0]];
	for (int i = 1; i < group.size(); i++) {
		if (weight[group[i]] > ww) {
			loser.push_back(w);
			ww = weight[group[i]];
			w = group[i];
		}
		else
			loser.push_back(group[i]);
	}
	return w;
}
int Q1056()
{
	int num, incre;
	scanf("%d %d", &num, &incre);
	weight.resize(num, 0);
	ranking.resize(num, 0);
	for (int i = 0; i < num; i++)
		scanf("%d", &weight[i]);
	for (int i = 0; i < num; i++) {
		int t;
		scanf("%d", &t);
		order.push(t);
	}
	vector<int> group;
	queue<int> tmpwinner;
	while (!order.empty()) {
		loser.clear();
		while (!order.empty()) {
			group.clear();
			while (group.size() < incre && !order.empty()) {
				group.push_back(order.front());
				order.pop();
			}
			tmpwinner.push(winner(group));
		}
		if (loser.size() == 0) {
			loser.push_back(tmpwinner.front());
			allMember.push_back(loser);
			break;
		}
		allMember.push_back(loser);
		order = tmpwinner;
		while(!tmpwinner.empty())
			tmpwinner.pop();
	}
	int cnt = 1;
	for (int i = allMember.size() - 1; i >= 0; i--) {
		if (i != allMember.size() - 1)
			cnt += allMember[i + 1].size();
		for (int j = 0; j < allMember[i].size(); j++) {
			ranking[allMember[i][j]] = cnt;
		}
	}
	printf("%d", ranking[0]);
	for (int i = 1; i < num; i++)
		printf(" %d", ranking[i]);
	system("pause");
	return 0;
}