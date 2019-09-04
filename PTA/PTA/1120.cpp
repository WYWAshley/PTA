#include<iostream>
using namespace std;

int Q1120()
{
	int num, cnt = 0;
	cin >> num;
	bool flag[37] = {0};
	for (int i = 0; i < num; i++) {
		int tmp, k = 0;
		cin >> tmp;
		while (tmp > 0) {
			k += tmp % 10;
			tmp /= 10;
		}
		if (!flag[k])
			cnt++;
		flag[k] = 1;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 37; i++) {
		if (flag[i]) {
			printf("%d", i);
			for (int j = i + 1; j < 37; j++)
				if (flag[j])
					printf(" %d", j);
			break;
		}
	}
	system("pause");
	return 0;
}