#include<iostream>
using namespace std;

char c[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
void trans(int n)
{
	char a = c[ n / 13];
	char b = c[ n % 13];
	printf("%c%c", a, b);
}
int Q1027()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#";
	trans(r);
	trans(g);
	trans(b);
	system("pause");
	return 0;
}