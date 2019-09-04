#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
using namespace std;
struct peo {
	int height;
	string name;
};
bool cmp(peo p1, peo p2) {
	if (p1.height != p2.height)
		return p1.height > p2.height;
	else
		return p1.name < p2.name;
}
void sort(vector<int> &v) {
	
}
int Q1109()
{
	int Num, rowNum;
	scanf("%d %d", &Num, &rowNum);
	vector<peo> vp;
	for (int i = 0; i < Num; i++) {
		peo p;
		cin >> p.name >> p.height;
		vp.push_back(p);
	}
	sort(vp.begin(), vp.end(), cmp);
	int row_n = Num / rowNum;
	int remain = Num - row_n * rowNum;
	int now = 0;
	list<string> ls;
	for (int i = 0; i < rowNum; i++) {
		int peoNum = row_n + (remain > 0);
		remain--;
		ls.push_back(vp[now].name);
		for (int j = 1; j < peoNum; j++) {
			if (j % 2 != 0)
				ls.push_front(vp[now + j].name);
			else
				ls.push_back(vp[now + j].name);
		}
		printf("%s", ls.front().c_str());
		ls.pop_front();
		while (!ls.empty()) {
			printf(" %s", ls.front().c_str());
			ls.pop_front();
		}
		printf("\n");
		now += peoNum;
	}
	system("pause");
	return 0;
}