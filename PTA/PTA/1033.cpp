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
	sta[0] = { 0.0, d };//��Ŀ�ĵؿ�����һ������վ���۸�Ϊ0���������
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &sta[i].price, &sta[i].dis);
	sort(sta.begin(), sta.end(), cmp);//���ռ۸�����
	double nowdis, maxdis = 0;//�ֱ�洢���ڵľ��룬��ʱ��������Զ��ʻ����
	double nowprice, total = 0;
	double left = 0;//ʣ�µ�����
	
	if (sta[0].dis != 0) {//����ʼ��û�м���վ
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else {
		nowprice = sta[0].price;
		nowdis = 0;
	}

	int cnt = 1;//��¼�����վ�����
	while (nowdis < d) {
		maxdis = nowdis + cap * unit;//���ڴ�վ�����ܵ������Զ����
		double minPriceDis = 0, minPrice = INF;
		bool flag = 0;//������Ǽ����ͻ���ֻ�ӵ���һվΪֹ
		for (int i = cnt; i <= n && sta[i].dis <= maxdis; i++) {//�ӳ������1��վ�㿪ʼ
			if (sta[i].dis <= nowdis) continue;
			cnt = i;
			if (sta[i].price < nowprice) {//�ҵ�������ʻ���������б����վ��۸�͵�
				flag = 1;
				total += ((sta[i].dis - nowdis) / unit - left) * nowprice;//��һ������վ��Ҫ��Ǯ
				left = 0.0;//�������վ��ʱ����Ϊ0
				nowprice = sta[i].price;
				nowdis = sta[i].dis;
				break;
			}
			if (sta[i].price < minPrice) {//û���ҵ���������˵ģ��Ǿ�ֻ�ܼ����������������˵�
				minPrice = sta[i].price;
				minPriceDis = sta[i].dis;
			}
		}
		if (flag == 0 && minPrice == INF) {//֮��û�м���վ�ˣ��Ǿ�����ʧ��
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