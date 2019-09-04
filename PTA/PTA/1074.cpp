#include<iostream>
#include<vector>
#include<map>
using namespace std;

int Q1074()
{
	int first, num, increment;
	scanf("%d%d%d", &first, &num, &increment);
	map<int, int> add_val;
	map<int, int> add_next;
	for (int i = 0; i < num; i++) {
		int add, val, next;
		scanf("%d%d%d", &add, &val, &next);
		add_val[add] = val;
		add_next[add] = next;
	}
	vector<int> v_add;
	v_add.push_back(0);
	while (first != -1) {
		v_add.push_back(first);
		first = add_next[first];
	}
	for (int i = 1; i + increment <= v_add.size(); i += increment) {
		for (int j = 0; j <= increment/2 - 1; j++) {
			swap(v_add[j + i], v_add[i + increment - 1 - j]);
		}
	}
	for (int i = 1; i < v_add.size(); i++) {
		printf("%05d %d ", v_add[i], add_val[v_add[i]]);
		if (i == v_add.size() - 1)
			printf("-1\n");
		else
			printf("%05d\n", v_add[i + 1]);
	}
	system("pause");
	return 0;
}