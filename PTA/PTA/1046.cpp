#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

//int shortdis(int i, int j, vector<int> &v) {
//	int tmp = 0;
//	if (i > j)
//		swap(i, j);
//	for (int k = i; k < j; k++) 
//		tmp += v[k];
//	return tmp;
//}
int findshotter(vector<int> v, int a, int b) {
	int sum1, sum2;
	sum1 = sum2 = 0;
	for (int i = a; i < b; i++) {
		sum1 += v[i];
	}
	int len = v.size();
	for (int i = b; i%len != a; i++)
	{
		sum2 += v[i % len];
	}
	return sum1 < sum2 ? sum1 : sum2;
}
int Q1046()
{
	int d;
	scanf("%d", &d);
	vector<int> dis(d);
	vector<int> cycle(d, 0);

	for (int i = 0; i < d; i++) {
		scanf("%d", &dis[i]);
	}
	for (int i = d-1; i >=0; i--)
	{
		cycle[i] += cycle[(i+1)%d] + dis[i];
	} 

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int big = max(a, b) - 1;
		int small = min(a, b) - 1;
		printf("%d\n", min(cycle[0] - cycle[small] + cycle[big], cycle[small] - cycle[big]));
	}

	system("pause");
	return 0;
}