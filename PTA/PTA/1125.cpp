#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int Q1125()//����һ������ͺ��ˣ�Ҫ���������ķ�����ע����priorityqueue��greater����
{
	int num;
	cin >> num;
	priority_queue<double, vector<double>, greater<double>> q;
	for (int i = 0; i < num; i++) {
		double t;
		scanf("%lf", &t);
		q.push(t);
	}
	while (q.size() > 1) {
		int t1 = q.top();
		q.pop();
		int t2 = q.top();
		q.pop();
		q.push((t1 + t2) / 2);
	}
	int res = q.top() / 1.0;
	printf("%d", res);
	system("pause");
	return 0;
}