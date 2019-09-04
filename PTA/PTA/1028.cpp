#include<iostream>
#include<map>
#include<set>
using namespace std;

int Q1028()
{
	int num, m;
	scanf("%d %d", &num, &m);
	if (m == 1) {
		map<int, string> na;
		map<int, int> gra;
		for (int i = 0; i < num; i++) {
			int id = 0, grade = 0;
			char name[9];
			scanf("%d %s %d", &id, name, &grade);
			na[id] = name;
			gra[id] = grade;
		}
		auto it1 = na.begin(); 
		auto it2 = gra.begin();
		for (; it1 != na.end() && it2 != gra.end(); it1++, it2++) {
			printf("%06d %s %d\n", it1->first, it1->second.c_str(), it2->second);
		}
	}
	else if (m == 2) {
		map<string, set<int>> na;
		map<int, int> gra;
		for (int i = 0; i < num; i++) {
			int id = 0, grade = 0;
			char name[9];
			scanf("%d %s %d", &id, name, &grade);
			na[name].insert(id);
			gra[id] = grade;
		}
		for (auto it1 = na.begin(); it1 != na.end(); it1++) {
			for (auto it3 = it1->second.begin(); it3 != it1->second.end(); it3++)
				printf("%06d %s %d\n", *it3, it1->first.c_str(), gra[*it3]);
		}
	}
	else if (m == 3) {
		map<int, string> na;
		map<int, set<int>> gra;
		for (int i = 0; i < num; i++) {
			int id = 0, grade = 0;
			char name[9];
			scanf("%d %s %d", &id, name, &grade);
			na[id] = name;
			gra[grade].insert(id);
		}
		for (auto it2 = gra.begin(); it2 != gra.end(); it2++) {
			for (auto it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
				printf("%06d %s %d\n", *it3, na[*it3].c_str(), it2->first);
		}
	}
	system("pause");
	return 0;
}