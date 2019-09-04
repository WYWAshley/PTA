#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

map<string, int> id;//获得id
map<int, string> name;//获得名字
int dial[2005][2005] = {0};//存取每段对话时间
int ti[2005] = {0};//每个人的时间
bool visited[2005] = {0};
int idnum = 0;//一共多少人
int tmpti = 0;
int tmpmember = 0;
int tmph = 0;
struct gang
{
	int head = 0;
	int member = 0;
};
int insert(string str)
{
	if (id[str] == 0) {
		idnum++;
		id[str] = idnum;
		name[idnum] = str;
		return idnum;
	}
	else
		return id[str];
}
void DFS(int n)
{
	tmpmember++;
	visited[n] = 1;
	if (ti[n] > ti[tmph])
		tmph = n;
	for (int i = 1; i <= idnum; i++) {
		if (dial[n][i] > 0){
			tmpti += dial[n][i];
			dial[n][i] = dial[i][n] = 0;
			if(visited[i] == 0)
				DFS(i);
		}
	}
}
bool cmp(gang g1, gang g2)
{
	return name[g1.head] < name[g2.head];
}
int Q1034()
{
	int num, thre;
	scanf("%d%d",&num, &thre);
	for (int i = 0; i < num; i++) {
		string n1, n2;
		n1.resize(4);
		n2.resize(4);
		int t;
		scanf("%s%s%d", &n1[0], &n2[0], &t);
		int id1 = insert(n1);
		int id2 = insert(n2);
		dial[id1][id2] += t;
		dial[id2][id1] += t;
		ti[id1] += t;
		ti[id2] += t;
	}
	vector<gang> v;
	for (int i = 1; i <= idnum; i++) {
		if (visited[i] == 0) {
			tmpti = 0;
			tmpmember = 0;
			tmph = i;
			DFS(i);
			if (tmpti > thre && tmpmember > 2) {
				gang g;
				g.head = tmph;
				g.member = tmpmember;
				v.push_back(g);
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	printf("%d\n",v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%s %d\n",name[v[i].head].c_str(), v[i].member);
	}
	system("pause");
	return 0;
}