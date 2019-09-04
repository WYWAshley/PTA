#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> res;
vector<int> tmp;
vector<int> weight;
bool link[103][103] = {false};
bool isFather[103] = {false};
int num, total;
bool cmp(vector<int> v1, vector<int> v2)
{
	int t = min(v1.size(), v2.size());
	for (int i = 0; i < t; i++) {
		if (v1[i] > v2[i])
			return true;
		else if (v1[i] < v2[i])
			return false;
	}
	return v1.size() > v2.size();
}
void DFS(int root, int now, vector<int> &tmp)
{
	now += weight[root];
	tmp.push_back(weight[root]);
	if (now == total && !isFather[root]) {
		res.push_back(tmp);
		tmp.pop_back();
		return;
	}
	else if (now > total) {
		tmp.pop_back();
		return;
	}
	for (int i = 0; i < num; i++) {
		if (link[root][i]) {
			link[root][i] = 0;
			link[i][root] = 0;
			DFS(i, now, tmp);
		}
	}
	if(!tmp.empty())
		tmp.pop_back();
	return;
}
int Q1053()
{
	int nonLeafNum;
	scanf("%d%d%d", &num, &nonLeafNum, &total);
	weight.resize(num, 0);
	for (int i = 0; i < num; i++)
		scanf("%d", &weight[i]);
	for (int i = 0; i < nonLeafNum; i++) {
		int father, chil, chilNum;
		scanf("%d %d", &father, &chilNum);
		isFather[father] = 1;
		for (int j = 0; j < chilNum; j++) {
			scanf("%d", &chil);
			link[father][chil] = true;
			link[chil][father] = true;
		}
	}
	DFS(0, 0, tmp);
	sort(res.begin(), res.end(),cmp);
	for (int i = 0; i < res.size(); i++) {
		printf("%d", res[i][0]);
		for (int j = 1; j < res[i].size(); j++) {
			printf(" %d", res[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}