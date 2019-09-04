#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Q1085()
{
	int num;
	long long p;
	scanf("%lld %lld", &num, &p);
	vector<int> v(num);
	for (int i = 0; i < num; i++)
		scanf("%lld", &v[i]);
	sort(v.begin(), v.end());
	int res = 0, j = 0;
	for (int i = 0; i < num; i++) {
		long long k = p * v[i];
		while (j < num  && v[j] <= k) j++;
		if (j - i > res)
			res = j - i;
	}
	printf("%d", res);
	system("pause");
	return 0;
}