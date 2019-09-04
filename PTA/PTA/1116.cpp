#include<iostream>
#include<map>
#include<vector>
using namespace std;

bool isPrime(int n) {
	if (n == 2)
		return 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int Q1116()
{
	int num;
	scanf("%d", &num);
	map<int, int> rank;
	bool flag[10000] = { false };
	for (int i = 1; i <= num; i++) {
		int id;
		scanf("%d", &id);
		rank[id] = i;
	}
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i<cnt; i++) {
		int nowID;
		scanf("%d", &nowID);
		printf("%04d: ", nowID);
		if (rank.find(nowID) == rank.end()) {
			printf("Are you kidding?\n");
		}
		else {
			if (flag[nowID]) {
				printf("Checked\n");
			}
			else {
				int r = rank[nowID];
				if (r == 1)
					printf("Mystery Award\n");
				else if (isPrime(r))
					printf("Minion\n");
				else
					printf("Chocolate\n");
				flag[nowID] = 1;
			}
		}
	}
	system("pause");
	return 0;
}