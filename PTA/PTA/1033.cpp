#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 99999999;
struct station {
	double price;
	double dis;
};
bool cmp(station a, station b) {
	return a.dis < b.dis;
}
int Q1033() {
	double cap, d, unit;
	int n;
	scanf("%lf%lf%lf%d", &cap, &d, &unit, &n);
	vector<station> sta(n + 1);
	sta[0] = { 0.0, d };//把目的地看做是一个加油站，价格为0，距离最大
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &sta[i].price, &sta[i].dis);
	sort(sta.begin(), sta.end(), cmp);//按照价格排序
	double nowdis, maxdis = 0;//分别存储现在的距离，此时加满油最远行驶距离
	double nowprice, total = 0;
	double left = 0;//剩下的油量
	
	if (sta[0].dis != 0) {//在起始点没有加油站
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else {
		nowprice = sta[0].price;
		nowdis = 0;
	}

	int cnt = 1;//记录到达的站点序号
	while (nowdis < d) {
		maxdis = nowdis + cap * unit;//若在此站加满能到达的最远距离
		double minPriceDis = 0, minPrice = INF;
		bool flag = 0;//分清楚是加满油还是只加到下一站为止
		for (int i = cnt; i <= n && sta[i].dis <= maxdis; i++) {//从除起点外1号站点开始
			if (sta[i].dis <= nowdis) continue;
			cnt = i;
			if (sta[i].price < nowprice) {//找到了在行驶最大距离内有比这个站点价格低的
				flag = 1;
				total += ((sta[i].dis - nowdis) / unit - left) * nowprice;//上一个加油站需要的钱
				left = 0.0;//到达这个站点时油量为0
				nowprice = sta[i].price;
				nowdis = sta[i].dis;
				break;
			}
			if (sta[i].price < minPrice) {//没有找到比这个便宜的，那就只能加满了再找相对最便宜的
				minPrice = sta[i].price;
				minPriceDis = sta[i].dis;
			}
		}
		if (flag == 0 && minPrice == INF) {//之间没有加油站了，那就任务失败
			nowdis += cap * unit;
			printf("The maximum travel distance = %.2f", nowdis);
			return 0;
		}
		else if (flag == 0 && minPrice != INF) {
			total += (nowprice * (cap - left));
			left = cap - (minPriceDis - nowdis) / unit;
			nowprice = minPrice;
			nowdis = minPriceDis;
		}
	}
	printf("%.2f", total);
	return 0;
}