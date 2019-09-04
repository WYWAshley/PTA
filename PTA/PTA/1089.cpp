#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int Q1089()
{
	int num;
	scanf("%d", &num);
	vector<int> initial(num);
	vector<int> now(num);
	bool flag = 1; //1为merge，0为insert
	for (int i = 0; i < num; i++) {
		int d;
		scanf("%d", &d);
		initial[i] = d;
	}
	for (int i = 0; i < num; i++) {
		int d;
		scanf("%d", &d);
		now[i] = d;
	}
	int t = 1;
	while (t < num && now[t - 1] <= now[t])//0到t-1位都已经排好了
		t++;
	int t2 = t;
	while (t2 < num && now[t2] == initial[t2]) 
		t2++;
	if (t2 == num)
		flag = 0;

	if (flag == 0) {
		printf("Insertion Sort\n");
		sort(now.begin(), now.begin() + t + 1);
	}
	else { 
		printf("Merge Sort\n");
		bool sorted = 1;
		t = 2;
		while (sorted) {
			for (int i = 0; i + 1 < num; i += t) {
					for (int j = 1; j < t && i + j < num; j++) {
					if (now[i + j] < now[i + j - 1]) {
						sorted = 0;
						break;
					}
				}
				if (sorted == 0)
					break;
			}
			if (sorted == 1)
				t *= 2;
		}
		int i;
		for (i = 0; i + t <= num; i += t)
			sort(now.begin() + i, now.begin() + i + t);
		if (num % t != 0)
			sort(now.begin() + i, now.end());
	}
	for (int i = 0; i < num; i++) {
		printf("%d", now[i]);
		if (i != num - 1)
			printf(" ");
	}
	system("pause");
	return 0;
}