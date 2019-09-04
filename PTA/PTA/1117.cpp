#include<iostream>
#include<queue>
using namespace std;


int Q1117()
{
	int num;
	scanf("%d", &num);
	priority_queue<int> q;
	//priority_queue<int, vector<int>, greater<int> >q1;优先队列的从小到大排序
	//优先队列自定义排序需要重新定义operator() >是从小到大
	for (int i = 0; i < num; i++) {
		int t;
		cin >> t;
		q.push(t);
	}
	int cnt = 0;
	while (!q.empty()) {
		int min = q.top();
		q.pop();
		cnt++;
		if (min <= cnt) {
			cnt--;
			break;
		}
	}
	cout << cnt;
	system("pause");
	return 0;
}