#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Q1037()
{
	int nc, np;
	scanf("%d", &nc);
	vector<int> v1(nc);
	for (int i = 0; i < nc; i++) {
		scanf("%d", &v1[i]);
	}
	scanf("%d", &np);
	vector<int> v2(np);
	for (int i = 0; i < np; i++) {
		scanf("%d", &v2[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int total = 0;
	for (int i = 0; i < nc && i < np; i++) {
		if (v1[i] < 0 && v2[i] < 0)
			total += v1[i] * v2[i];
		else
			break;
	}
	for (int i = nc - 1, j = np - 1; i >= 0 && j >= 0; i--, j--) {
		if (v1[i] > 0 && v2[j] > 0)
			total += v1[i] * v2[j];
		else
			break;
	}
	printf("%d\n", total);
	system("pause");
	return 0;
}