#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

bool cmp (pair<int, int> p1, pair<int, int> p2) {
	if (p1.second != p2.second)
		return p1.second > p2.second;
	else
		return p1.first < p2.first;
}
int Q1129()//巧妙点在于设置两个vector，这样就不用每次把全部的pair都进行排序了
{
	int inum, rnum;
	scanf("%d %d", &inum, &rnum);
	map<int, int> vm;
	vector<pair<int, int>> vres;
	vector<bool> hasShow(inum+1, false), isBig(inum + 1, false);
	int query;
	scanf("%d", &query);

	vres.push_back(make_pair(query, 1));
	hasShow[query] = true; isBig[query] = true;

	for (int i = 1; i < inum; i++) {
		scanf("%d", &query);
		printf("%d:", query);
		sort(vres.begin(), vres.end(), cmp);
		for (int j = 0; j < vres.size() && j <= i; j++)
			printf(" %d", vres[j].first);
		printf("\n");

		if (isBig[query]) {
			for (int j = 0; j < vres.size(); j++) {
				if (vres[j].first == query) {
					vres[j].second++;
					break;
				}
			}
		}
		else {
			if (hasShow[query])
				vm[query]++;
			else {
				hasShow[query] = true;
				vm[query] = 1;
				if (vres.size() < rnum) {
					isBig[query] = true;
					vres.push_back(make_pair(query, 1));
					vm.erase(query);
					continue;
				}
			}
			int j = vres.size() - 1;
			if (vres[j].second < vm[query] || vres[j].second == vm[query] && vres[j].first > query) {
				pair<int, int> temp = vres[j];
				vres[j] = make_pair(query, vm[query]);
				vm.erase(query);
				vm[temp.first] = temp.second;
				isBig[query] = true;
				isBig[temp.first] = false;
			}
		}
	}
	system("pause");
	return 0;
}