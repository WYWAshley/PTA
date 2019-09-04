#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student
{
	int id, ge, gi, total;
	vector<int> prefer;
};
bool cmp(const student &s1, const student &s2)
{
	if (s1.total != s2.total)
		return s1.total > s2.total;
	else {
		if (s1.ge != s2.ge)
			return s1.ge > s2.ge;
		else
			return s1.id < s2.id;
	}
}
bool cmp2(int &t1, int &t2)
{
	return t1 < t2;
}
int Q1080()
{
	int num_stu, num_sch, num_cho;
	scanf("%d %d %d", &num_stu, &num_sch, &num_cho);
	vector<int> quota(num_sch);
	vector<student> v_stu(num_stu);
	for (int i = 0; i < num_sch; i++)
		scanf("%d", &quota[i]);
	for (int i = 0; i < num_stu; i++) {
		v_stu[i].id = i;
		scanf("%d%d", &v_stu[i].ge, &v_stu[i].gi);
		v_stu[i].total = v_stu[i].ge + v_stu[i].gi;
		v_stu[i].prefer.resize(num_cho);
		for (int j = 0; j < num_cho; j++)
			scanf("%d", &v_stu[i].prefer[j]);
	}
	sort(v_stu.begin(), v_stu.end(), cmp);

	vector<int> count(num_sch, 0), total(num_sch), ge(num_sch);
	vector<vector<int>> addmit(num_sch);
	for (int i = 0; i < num_stu; i++) {
		for (int j = 0; j < num_cho; j++) {
			int index = v_stu[i].prefer[j];
			if (count[index] < quota[index]) {
				addmit[index].push_back(v_stu[i].id);
				count[index]++;
				total[index] = v_stu[i].total;
				ge[index] = v_stu[i].ge;
				break;
			}
			else if (total[index] == v_stu[i].total && ge[index] == v_stu[i].ge) {
				addmit[index].push_back(v_stu[i].id);
				count[index]++;
				total[index] = v_stu[i].total;
				ge[index] = v_stu[i].ge;
				break;
			}
		}
	}
	for (int i = 0; i < num_sch; i++) {
		sort(addmit[i].begin(), addmit[i].end(), cmp2);
		for (int j = 0; j < addmit[i].size(); j++) {
			if (j != 0)
				printf(" ");
			printf("%d", addmit[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}