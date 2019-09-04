#include<iostream>
#include<math.h>
using namespace std;
//得用乘法，用除法会超时
int Q1096()
{
	int n;
	scanf("%d", &n);
	int res = 0, first, max = sqrt(n);
	for (int i = 2; i <= max; i++) {
		int j, tmp = 1;
		for (j = i; j <= max; j++) {
			tmp *= j;
			if (n % tmp != 0)
				break;
		}
		if (j - i > res) {
			res = j - i;
			first = i;
		}
	}
	if (res == 0) {
		printf("1\n%d", n);
	}
	else {
		printf("%d\n%d", res, first);
		for (int i = 1; i < res; i++)
			printf("*%d", first + i);
	}
	system("pause");
	return 0;
}