#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fun(int n, int &max, int &min) {
	int a[4];
	for (int i = 0; i < 4; i++) {
		a[i] = n % 10;
		n = n / 10;
	}
	sort(a, a + 4);
	min = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
	max = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}
int Q1066()
{
	int n;
	scanf("%d", &n);
	do {
		if (n % 1111 == 0) {
			printf("%04d - %04d = 0000\n", n, n);
			break;
		}
		else {
			int max, min;
			fun(n, max, min);
			int t = max - min;
			n = t;
			printf("%04d - %04d = %04d\n", max, min, t);
		}
	} while (n != 6174);

	system("pause");
	return 0;
}