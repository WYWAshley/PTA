#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Q1098()
{
	int num;
	scanf("%d", &num);
	vector<int> v1, v2;
	for (int i = 0; i < num; i++)
		scanf("%d", v1[i]);
	for (int i = 0; i < num; i++)
		scanf("%d", v2[i]);
	int ii = 0;
	while (ii + 1 < num && v2[ii] <= v2[ii + 1]) ii++;
	int jj = ii;
	while (jj < num && v1[jj] == v2[jj]) jj++;
	if (jj == num - 1) {
		printf("Insertion Sort\n");
		sort(v2.begin(), v2.begin() + ii);
	}
	else {
		printf("Heap Sort\n");
		int max = v2[0], i = num - 1;
		while (i >= 0 && v2[i] >= v2[i - 1]) i--;//ÐèÒªÅÅÐò¡¾0£¬i¡¿
		vector<int> heap;
		for (int j = 1; j <= i; j++)
			heap.push_back(v2[j]);

	}
	system("pause");
	return 0;
}