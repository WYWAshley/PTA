#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct magnet {
	int age, wealth;
	string name;
};
bool cmp(magnet m1, magnet m2) {
	if (m1.wealth != m2.wealth)
		return m1.wealth > m2.wealth;
	else {
		if (m1.age != m2.age)
			return m1.age < m2.age;
		else {
			return m1.name < m2.name;
		}
	}
}
int Q1055()
{
	int num, qnum;
	scanf("%d %d", &num, &qnum);
	vector<struct magnet> v(num);
	for (int i = 0; i < num; i++)
		cin >> v[i].name >> v[i].age >> v[i].wealth;
	sort(v.begin(),v.end(),cmp);
	for (int i = 0; i < qnum; i++) {
		int cap, a1, a2;
		scanf("%d %d %d", &cap, &a1, &a2);
		printf("Case #%d:\n", i+1);
		int cnt = 0;
		for (int j = 0; cnt < cap && j < v.size(); j++) {
			if (v[j].age <= a2 && v[j].age >= a1) {
				printf("%s %d %d\n", v[j].name.c_str(), v[j].age, v[j].wealth);
				cnt++;
			}
		}
		if (cnt == 0)
			printf("None");
	}
	system("pause");
	return 0;
}