#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;

struct stu
{
	int gp, gm, gf, g;
	string name;
	//学习一下默认构造函数怎么写
	stu(string nm="",int p=-1,int m=-1,int f=-1,int gg=0):name(nm),gp(p),gm(m),gf(f),g(gg){}
	bool operator < (const stu &a)const {
		return g == a.g ? name < a.name : g >a.g;
	}
};
int Q1137()
{
	int p, m, n;
	scanf("%d %d %d", &p, &m, &n);
	map<string, stu> mp;//这里用<string, struct>可以减少存储
	vector<stu> v;
	for (int i = 0; i < p; i++) {
		string name;
		int gp;
		cin >> name >> gp;
		if (gp >= 200)
			mp[name] = stu(name, gp);
	}
	for (int i = 0; i < m; i++) {
		string name;
		int gm;
		cin >> name >> gm;
		if (mp.count(name))//用count函数返回值为0时是找不到
			mp[name].gm = gm;
	}
	for (int i = 0; i < n; i++) {
		string name;
		int gf;
		cin >> name >> gf;
		if (mp.count(name)) {
			mp[name].gf = gf;
			int final = gf;
			if (mp.count(name)) {
				if (mp[name].gm > gf)
					final = floor(0.4*mp[name].gm + 0.6*gf + 0.5);
			}
			if (final >= 60) {
				mp[name].g = final;
				v.push_back(mp[name]);
			}
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		stu s = v[i];
		printf("%s %d %d %d %d\n", s.name.c_str(), s.gp, s.gm, s.gf, s.g);
	}
	system("pause");
	return 0;;
}