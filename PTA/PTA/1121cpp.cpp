#include<iostream>
#include<queue>
using namespace std;
#define MAXNUM 100005

int Q1121()
{
	int couple[MAXNUM] = { MAXNUM - 1};
	bool flag[MAXNUM] = { false };
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		couple[c1] = c2;
		couple[c2] = c1;
	}
	scanf("%d", &num);
	queue<int> q1;
	priority_queue<int, vector<int>, greater<int>> q2;
	for (int i = 0; i < num; i++) {
		int guest;
		scanf("%d", &guest);
		flag[guest] = true;
		q1.push(guest);
	}
	while (!q1.empty()) {
		if (!flag[couple[q1.front()]])
			q2.push(q1.front());
		q1.pop();
	}
	printf("%d\n", q2.size());
	while (!q2.empty()) {
		printf("%05d", q2.top());
		q2.pop();
		if (q2.size() > 0)
			printf(" ");
	}
	system("pause");
	return 0;
}