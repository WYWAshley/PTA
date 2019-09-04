#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct mooncake
{
	double amount, price, unit;
};
bool cmp(mooncake m1, mooncake m2) {
	return m1.unit > m2.unit;
}
int Q1070()
{
	int num, total;
	scanf("%d %d", &num, &total);
	vector<mooncake> v;
	v.resize(num);
	for (int i = 0; i < num; i++)
		scanf("%lf", &v[i].amount);
	for (int i = 0; i < num; i++) {
		scanf("%lf", &v[i].price);
		v[i].unit = v[i].price / v[i].amount;
	}
	sort(v.begin(), v.end(), cmp);
	int cnt = 0;
	double res = 0;
	while (total >= 0 && cnt < num) {
		if (v[cnt].amount <= total) {
			res += v[cnt].price;
			total -= v[cnt].amount;
			cnt++;
		}
		else {
			res += v[cnt].unit * total;
			break;
		}
	}
	printf("%.2f\n", res);
	system("pause");
	return 0;
}