#include<iostream>
#include<queue>
using namespace std;


int Q1117()
{
	int num;
	scanf("%d", &num);
	priority_queue<int> q;
	//priority_queue<int, vector<int>, greater<int> >q1;���ȶ��еĴ�С��������
	//���ȶ����Զ���������Ҫ���¶���operator() >�Ǵ�С����
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