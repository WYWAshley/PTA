#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int l, h;
struct man
{
	int id;
	int v, t;
	int flag = -1;//0 for sage, 1 for noble men, 2 for fool men and 3 for others
};
bool cmp(man m1, man m2) {
	if (m1.flag != m2.flag)
		return m1.flag < m2.flag;
	else {
		int g1 = m1.t + m1.v, g2 = m2.t + m2.v;
		if (g1 != g2)
			return g1 > g2;
		else {
			if (m1.v != m2.v)
				return m1.v > m2.v;
			else
				return m1.id < m2.id;
		}
	}
}
int Q1062()
{
	int num;
	cin >> num >> l >> h;
	vector<man> v;
	for (int i = 0; i < num; i++) {
		man m;
		cin >> m.id >> m.v >> m.t;
		if (m.v < l || m.t < l) // not be ranked
			continue;
		else if (m.v >= h && m.t >= h) //sages
			m.flag = 0;
		else if (m.t < h && m.v >= h) //noble men
			m.flag = 1;
		else if (m.t < h && m.v < h && m.v >= m.t) //fool men
			m.flag = 2;
		else
			m.flag = 3;
		v.push_back(m);
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%08d %d %d\n", v[i].id, v[i].v, v[i].t);
	system("pause");
	return 0;
}