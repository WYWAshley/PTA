#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	int add = -1, val= -1, tail = -1;
	bool flag = false;
} v[100000];
bool cmp(node n1, node n2)
{
	if (!(n1.flag && n2.flag))
		return n1.flag > n2.flag;
	else
		return n1.val < n2.val;
}
int Q1052()
{
	int num;
	scanf("%d", &num);
	int h;
	scanf("%d", &h);
	for (int i = 0; i < num; i++) {
		node n;
		scanf("%d %d %d", &n.add, &n.val, &n.tail);
		v[n.add] = n;
	}
	int cnt = 0;
	while (h != -1) {
		v[h].flag = true;
		h = v[h].tail;
		cnt++;
	}
	if (cnt == 0) {
		printf("0 -1");
	}
	else {
		sort(v, v + 100000, cmp);
		printf("%d %05d\n", cnt, v[0].add);
		for (int i = 0; i < cnt; i++) {
			printf("%05d %d", v[i].add, v[i].val);
			if (i != cnt - 1)
				printf(" %05d\n", v[i+1].add);
			else
				printf(" -1\n");
		}
	}
	system("pause");
	return 0;
}