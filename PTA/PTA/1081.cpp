#include<iostream>
#define ll long long
using namespace std;
ll gcf(ll a, ll b)
{
	if (b == 0)
		return abs(a);
	else
		return gcf(b, a % b);
}
int Q1081()
{
	int num;
	ll sumn = 0, sumd = 1, gcfvalue;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		ll a, b;
		scanf("%lld/%lld", &a, &b);
		gcfvalue = gcf(a, b);
		a = a / gcfvalue;
		b = b / gcfvalue;
		sumn = sumn * b + a * sumd;
		sumd = b * sumd;
		gcfvalue = gcf(sumn, sumd);
		sumn = sumn / gcfvalue;
		sumd = sumd / gcfvalue;
	}
	ll integer = sumn / sumd;
	sumn = sumn - integer * sumd;
	if (integer != 0) {
		printf("%lld", integer);
		if (sumn != 0)
			printf(" ");
	}
	if (sumn != 0)
		printf("%lld/%lld", sumn, sumd);
	if (integer == 0 && sumn == 0)
		printf("0");
	system("pause");
	return 0;
}