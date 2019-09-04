#include<iostream>
#include<vector>
using namespace std;

int Q1044()
{
	vector<int> sub;
	int num, money, min = 999999999;
	scanf("%d%d", &num, &money);
	vector<int> chain(num+1);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &chain[i]);
	}
	int tmp;
	for (int i = 1; i <= num; i++) {
		int j = i;
		tmp = chain[j];
		while (tmp < money && j + 1 <= num)
			tmp += chain[++j];
		if (tmp < money)
			break;
		if (tmp > min)
			continue;
		if (tmp < min) {
			min = tmp;
			sub.clear();
		}
		sub.push_back(i);
		sub.push_back(j);
	}
	for (int i = 1; i < sub.size(); i += 2) {
		printf("%d-%d\n", sub[i - 1], sub[i]);
	}
	system("pause");
	return 0;
}