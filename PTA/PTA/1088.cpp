#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll gcf(ll numer, ll denomi) {
	if (denomi == 0)
		return numer;
	else
		return gcf(denomi, numer % denomi);
}
void print(ll sum1, ll sum2) {
	if (sum1 == 0) {
		printf("0");
		return;
	}
	ll t = gcf(sum1, sum2);
	sum1 /= t;
	sum2 /= t;
	if (sum2 < 0) {
		sum2 = -sum2;
		sum1 = -sum1;
	}
	ll integ = sum1 / sum2;
	sum1 -= sum2 * integ;
	if (integ == 0 && sum1 == 0)
		printf("0");
	if (sum1 < 0 || integ < 0)
		printf("(-");
	if (integ != 0) {
		printf("%lld", abs(integ));
		if (sum1 != 0)
			printf(" ");
	}
	if (sum1 != 0)
		printf("%lld/%lld", abs(sum1), abs(sum2));
	if (sum1 < 0 || integ < 0)
		printf(")");
}
void sum(ll &a1, ll &b1, ll &a2, ll &b2) {
	ll sum1 = a1 * b2 + a2 * b1;
	ll sum2 = b1 * b2;
	/*ll t = gcf(sum1, sum2);
	sum1 /= t;
	sum2 /= t;*/
	print(sum1, sum2);
}
void substract(ll &a1, ll &b1, ll &a2, ll &b2) {
	ll sum1 = a1 * b2 - a2 * b1;
	ll sum2 = b1 * b2;
	print(sum1, sum2);
}
void multiply(ll &a1, ll &b1, ll &a2, ll &b2) {
	ll sum1 = a1 * a2;
	ll sum2 = b1 * b2;
	print(sum1, sum2);
}
void divide(ll &a1, ll &b1, ll &a2, ll &b2) {
	if (a2 == 0) {
		printf("Inf");
		return;
	}
	ll sum1 = a1 * b2;
	ll sum2 = b1 * a2;
	print(sum1, sum2);
}
int Q1088()
{
	ll a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	ll t = gcf(a1, b1);
	a1 /= t;
	b1 /= t;
	t = gcf(a2, b2);
	a2 /= t;
	b2 /= t;
	char oper[4] = { '+', '-', '*', '/' };
	for (ll i = 0; i < 4; i++) {
		print(a1, b1);
		printf(" %c ", oper[i]);
		print(a2, b2);
		printf(" = ");
		if (i == 0)
			sum(a1, b1, a2, b2);
		if (i == 1)
			substract(a1, b1, a2, b2);
		if (i == 2)
			multiply(a1, b1, a2, b2);
		if (i == 3)
			divide(a1, b1, a2, b2);
		printf("\n");
	}

	system("pause");
	return 0;
}