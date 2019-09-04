#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int Q1051()
{
	int cap, num, k;
	stack<int> stack;
	queue<int> queue;
	vector<int> v;
	scanf("%d %d %d", &cap, &num, &k);

	for (int i = 0; i < k; i++){
		bool flag = 1;
		v.clear();
		while(!stack.empty())
			stack.pop();
		while(!queue.empty())
			queue.pop();
		for (int i = 1; i <= num; i++)
			queue.push(i);
		int first;
		scanf("%d", &first);
		v.push_back(first);
		for (int i = 1; i < num; i++) {
			int t;
			scanf("%d", &t);
			v.push_back(t);
		}
		if (first > 1) { //�Ƚ����һ������
			for (int j = 1; j <= first; j++) { //��С�ڵ�һ���������ְ�˳��push��stack��
				queue.pop();
				stack.push(j);
			}
			if (stack.size() > cap){ //��������capacity���ǲ�������
				printf("NO\n");
				continue;
			}
			stack.pop();
		}
		if(first == 1)
			queue.pop();		
		for (int j = 1; j < num; j++) {
			int t = v[j];
			if (queue.empty() || (!queue.empty() && t < queue.front())) { //�ڶ�ջ����
				if(!stack.empty() && stack.top() == t)
					stack.pop();
				else {
					printf("NO\n");
					flag = 0;
					break;
				}
			}
			else { 
				if (t == queue.front())
					queue.pop();
				else { //�ڶ�������
					while (!queue.empty() && queue.front() <= t) {
						stack.push(queue.front());
						queue.pop();
					}
					if (stack.size() > cap) {
						printf("NO\n");
						flag = 0;
						break;
					}
					stack.pop();
				}
			}
		}
		if(flag == 1)
			printf("YES\n");
	}
		

	system("pause");
	return 0;
}