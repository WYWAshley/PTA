#include<iostream>
#include<queue>
using namespace std;
#define ll long long

int Q1029()
{
	queue<int>a, b;
	int len1, len2, tmp;
	scanf("%d", &len1);
	for (int i = 0; i < len1; i++) {
		scanf("%d", &tmp);
		a.push(tmp);
	}
	scanf("%d", &len2);
	int mid = (len1 + len2 - 1) / 2, count = 0, j = 0;//j用于存储序列2一共输入了几次
	while (1) {
		if (j < len2) {
			scanf("%d", &tmp);
			b.push(tmp);
			j++;
		}
		if (count == mid)
			break;
		if (a.empty()) {
			b.pop();
			count++;
			continue;
		}
		else if (b.empty()) {
			a.pop();
			count++;
			continue;
		}
		else if (a.front() < b.front()) {
			a.pop();
			count++;
			continue;
		}
		else {
			b.pop();
			count++;
			continue;
		}
	}
	if (a.empty())
		printf("%d\n", b.front());
	else if (b.empty())
		printf("%d\n", a.front());
	else
		printf("%d\n", (a.front() <= b.front() ? a.front() : b.front()));
	
	return 0;
}
