#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Q1113()
{
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
		sum += seq[i];
	}
	sort(seq.begin(), seq.end());
	if (n % 2 == 0)
		printf("0 ");
	else
		printf("1 ");
	int cnt = n / 2;
	int sum2 = 0;
	for (int i = cnt; i < n; i++)
		sum2 += seq[i];
	printf("%d", sum2 - (sum - sum2));
	system("pause");
	return 0;
}