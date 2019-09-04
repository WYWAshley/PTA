#include<iostream>
#include<vector>
using namespace std;

struct node {
	int add, key, next;
};
int Q1097()
{
	int first, num;
	scanf("%d %d", &first, &num);
	vector<node> v(100001), v1, v2;
	bool flag[10001] = {false};
	for (int i = 0; i < num; i++) {
		node n;
		int a;
		scanf("%d", &a);
		v[a].add = a;
		scanf("%d %d", &v[a].key, &v[a].next);
	}
	while (first != -1) {
		if (!flag[abs(v[first].key)]) {
			flag[abs(v[first].key)] = true;
			v1.push_back(v[first]);
		}
		else
			v2.push_back(v[first]);
		first = v[first].next;
	}
	for (int i = 0; i < v1.size(); i++) {
		printf("%05d %d ", v1[i].add, v1[i].key);
		if (i == v1.size() - 1)
			printf("-1\n");
		else
			printf("%05d\n", v1[i + 1].add);
	}
	for (int i = 0; i < v2.size(); i++) {
		printf("%05d %d ", v2[i].add, v2[i].key);
		if (i == v2.size() - 1)
			printf("-1\n");
		else
			printf("%05d\n", v2[i + 1].add);
	}
	system("pause");
	return 0;
}