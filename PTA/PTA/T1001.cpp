#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_COST 999999
using namespace std;

struct edge {
	int city_a, city_b, cost, avali;
	bool operator <(edge &s) const {
		return avali != s.avali ? avali > s.avali : cost < s.cost;
	}
	void input() {
		scanf("%d %d %d %d", &city_a, &city_b, &cost, &avali);
	}
};
vector<edge> ve;
vector<int> fath, co;
int getfath(int x)
{
	return x == fath[x] ? x : fath[x] = getfath(fath[x]);
}
int QT1001() {
	int cityNum, edgeNum;
	scanf("%d %d", &cityNum, &edgeNum);
	ve.resize(edgeNum);
	fath.resize(cityNum + 1);
	co.resize(cityNum + 1, 0);
	for (int i = 0; i < edgeNum; i++)
		ve[i].input();
	sort(ve.begin(), ve.end());

	int maxres = 0;
	vector<int> ans;
	for (int i = 1; i <= cityNum; i++) {//生成最小生成树
		int counter = 1;
		for (int j = 1; j <= cityNum; j++)//记录当前节点的根节点
			fath[j] = j;
		for (int j = 0; j < ve.size(); j++) {
			int a = ve[j].city_a, b = ve[j].city_b;
			if (a == i || b == i)//去除失陷的城市节点
				continue;
			if (getfath(a) == getfath(b))//这条边是不需要的
				continue;
			if(ve[j].avali == 0)//加上这条边的开销
				co[i] += ve[j].cost;
			counter++;
			fath[getfath(a)] = fath[getfath(b)];
		}
		if (counter < cityNum - 1)
			co[i] = MAX_COST;
		if (maxres < co[i]) {
			ans.clear();
			ans.push_back(i);
			maxres = co[i];
		}
		else if (maxres == co[i])
			ans.push_back(i);
	}
	if (maxres == 0)
		cout << 0 << endl;
	else {
		cout << ans[0];
		for (int i = 1; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}