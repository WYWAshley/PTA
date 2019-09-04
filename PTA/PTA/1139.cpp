#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;

struct matchMaker {
	int f1, f2;
	matchMaker(int ff1, int ff2) { f1 = ff1; f2 = ff2; }
};
bool cmp(matchMaker m1, matchMaker m2) {
	return m1.f1 == m2.f1 ?
		m1.f2 < m2.f2 : m1.f1 <= m2.f1;
}
int Q1139()
{
	int pnum, rnum;
	scanf("%d %d", &pnum, &rnum);
	vector<vector<bool>> isFriend(pnum);
	for (int i = 0; i < pnum; i++) {
		isFriend[i].resize(pnum, false);
	}
	map<int, vector<int>> v1;
	//*如果用int接收一对朋友，-0000和0000对于int来说都是0，将无法得知这个人的性别
	map<string, int> id;
	map<int, string> name;
	int cnt = 0;
	for (int i = 0; i < rnum; i++) {
		string p1, p2;
		cin >> p1 >> p2;
		if (id.find(p1) == id.end()) {
			id[p1] = cnt++;
			name[cnt - 1] = p1;
		}
		if (id.find(p2) == id.end()) {
			id[p2] = cnt++;
			name[cnt - 1] = p2;
		}
		if (p1[0] == '-' && p2[0] == '-' || p1[0] != '-' && p2[0] != '-') {//只保存同性朋友
			v1[id[p1]].push_back(id[p2]);
			v1[id[p2]].push_back(id[p1]);
		}
		isFriend[id[p1]][id[p2]] = isFriend[id[p2]][id[p1]] = true;
	}

	int qnum;
	scanf("%d", &qnum);
	for (int i = 0; i < qnum; i++) {
		string p1, p2;
		cin >> p1 >> p2;
		//注意当不存在这个人的时候因为用的map所以要单独写，不然map会加上这个人的信息
		if (id.find(p1) == id.end() || id.find(p2) == id.end()) {
			printf("0\n");
			continue;
		}
		vector<struct matchMaker> res;
		for (int j = 0; j < v1[id[p1]].size(); j++) {
			int f1 = v1[id[p1]][j];
			if (f1 == id[p2])//当前朋友就是p2舍弃
				continue;
			for (int k = 0; k < v1[id[p2]].size(); k++) {
				int f2 = v1[id[p2]][k];
				//若当前朋友就是B或者B的同性朋友就是A时舍弃该结果,这个忘记了
				if (f2 == f1 || f2 == id[p1]) {
					continue;
				}
				if (isFriend[f1][f2]) {
					res.push_back(matchMaker(abs(stoi(name[f1])), abs(stoi(name[f2]))));
				}
			}
		}
		printf("%d\n", res.size());
		if (res.size() == 0) continue;
		else {
			sort(res.begin(), res.end(), cmp);
			for (int j = 0; j < res.size(); j++)
				//输出的时候四位格式忘记了
				printf("%04d %04d\n", res[j].f1, res[j].f2);
		}
	}
	system("pause");
	return 0;
}