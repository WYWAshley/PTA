#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Q1048()
{
	int num, total;
	scanf("%d %d", &num, &total);
	int flag[505] = {0};
	for (int i = 0; i < num; i++) {
		int d;
		scanf("%d", &d);
		flag[d]++;
	}
	for (int i = 1; i <= 500; i++) {
		if (flag[i] > 0) {
			int remain = total - i;
			if (remain < i)
				break;
			flag[i]--;
			if (flag[remain] > 0) {
				printf("%d %d\n", i, remain);
				system("pause");
				return 0;
			}
			flag[i]++;
		}	
	}
	printf("No Solution\n");
	system("pause");
	return 0;
}