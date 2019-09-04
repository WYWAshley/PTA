#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
struct fam {
	int id, cnt;
	double avgEstate, avgArea;
};
bool cmp(fam a1, fam a2) {
	if (a1.avgArea != a2.avgArea)
		return a1.avgArea > a2.avgArea;
	else
		return a1.id < a2.id;
}
int family[10000], total_estate[10000], total_area[10000];
vector<set<int>> member(10000);
int Q1114()
{
	for (int i = 0; i < 10000; i++)
		family[i] = i;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		vector<int> tmpset;
		int ID, fath, moth, k;
		scanf("%d %d %d %d", &ID, &fath, &moth, &k);
		tmpset.push_back(family[ID]);
		if(fath != -1)
			tmpset.push_back(family[fath]);
		if(moth != -1)
			tmpset.push_back(family[moth]);
		for (int j = 0; j < k; j++) {
			int chil;
			scanf("%d", &chil);
			tmpset.push_back(family[chil]);
		}
		int estate, area;
		scanf("%d %d", &estate, &area);
		int min = *min_element(tmpset.begin(), tmpset.end());
		total_area[min] += area;
		total_estate[min] += estate;
		for (int j = 0; j < tmpset.size(); j++) {
			int now = tmpset[j];
			if (now == min)
				continue;
			family[now] = min;
			member[min].insert(now);
			for (std::set<int>::iterator it = member[now].begin(); 
				it != member[now].end(); it++) {
				member[min].insert(*it);
				family[*it] = min;
			}
			member[now].clear();
			total_estate[min] += total_estate[now];
			total_estate[now] = 0;
			total_area[min] += total_area[now];
			total_area[now] = 0;
		}
	}
	vector<struct fam> ans;
	for (int i = 0; i < 10000; i++) {
		if (total_estate[i] > 0 || total_area[i] > 0) {
			fam a;
			a.id = i;
			a.cnt = member[i].size() + 1;
			a.avgArea = total_area[i] * 1.0 / a.cnt;
			a.avgEstate = total_estate[i] * 1.0 / a.cnt;
			ans.push_back(a);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%04d %d %.03f %.03f\n", ans[i].id, ans[i].cnt, ans[i].avgEstate, ans[i].avgArea);
	}
	system("pause");
	return 0;
}