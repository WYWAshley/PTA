#include<iostream>
using namespace std;

int Q1058()
{
	int g1, s1, k1, g2, s2, k2, g, s, k;
	scanf("%d.%d.%d %d.%d.%d", &g1,&s1,&k1, &g2,&s2,&k2);
	k = k1 + k2;
	s = s1 + s2 + k / 29;
	k = k % 29;
	g = g1 + g2 + s / 17;
	s = s % 17;
	printf("%d.%d.%d",g, s, k);
	system("pause");
	return 0;
}