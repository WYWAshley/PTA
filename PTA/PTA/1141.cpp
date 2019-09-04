#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;

struct insti
{
	int score[3] = {0};
	string school;
	double tws = 0.0;
	int ns;
	insti(string s, int n) { school = s; ns = n; }
};
bool cmp(insti i1, insti i2) {
	if (i1.tws != i2.tws)
		return i1.tws > i2.tws;
	else {
		if (i1.ns != i2.ns)
			return i1.ns < i2.ns;
		else
			return i1.school < i2.school;
	}
}
int Q1141()
{
	int num, cnt = 0;
	set<string> se;
	unordered_map<string, int> ma;
	vector<struct insti> v;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string no, sch;
		int score;
		cin >> no >> score >> sch;
		//转化为小写
		transform(sch.begin(), sch.end(), sch.begin(), ::towlower);
		if(se.insert(no).second == false)//已经存在了
			continue;
		if (ma.find(sch) == ma.end()) {
			ma[sch] = cnt++;
			v.push_back(insti(sch, 1));
		}
		else {
			v[ma[sch]].ns++;
		}
		//为什么要分开来算？因为double的精度问题
		if (no[0] == 'B')
			v[ma[sch]].score[0] += score;
		if (no[0] == 'A')
			v[ma[sch]].score[1] += score;
		if (no[0] == 'T')
			v[ma[sch]].score[2] += score;
	}
	for (int i = 0; i < v.size(); i++) {
		v[i].tws = v[i].score[0] * 2 / 3 + v[i].score[1] + v[i].score[2] * 3 / 2;
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	int rank = 1;
	for (int i = 0; i < v.size(); i++) {
		//这个排名的方法很赞哦
		if (i > 0 && floor(v[i].tws) != floor(v[i - 1].tws))
			rank = i + 1;
		cout << rank << " " << v[i].school << " " << floor(v[i].tws) << " " << v[i].ns << endl;
	}
	system("pause");
	return 0;
}