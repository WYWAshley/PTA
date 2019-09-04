#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct student
{
	string name, id;
	int grade;
};
bool cmp(student &s1, student &s2) {
	return s1.grade > s2.grade;
}
int Q1083()
{
	int num;
	scanf("%d", &num);
	vector<student> v;
	for (int i = 0; i < num; i++) {
		student s;
		scanf("%s %s %d", &s.name[0], &s.id[0], &s.grade);
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	int l, h;
	scanf("%d %d", &l, &h);
	bool flag = 0;
	for (int i = 0; i < num; i++) {
		if (v[i].grade < l || v[i].grade > h)
			continue;
		else {
			printf("%s %s\n", v[i].name.c_str(), v[i].id.c_str());
			flag = 1;
		}
	}
	if (flag == 0)
		printf("NONE\n");
	system("pause");
	return 0;
}