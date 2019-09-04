#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node
{
	int next;
	bool flag;
}v[100005];
int Q1032()
{
	int adr1, adr2, n;
	cin >> adr1 >> adr2 >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		char c;
		cin >> a >> c >> b;
		v[a] = {b, false};
	}
	while (adr1 != -1 ) {
		v[adr1].flag = true;
		adr1 = v[adr1].next;
	}
	while (adr2 != -1) {
		if (v[adr2].flag == true)
			break;
		else
			adr2 = v[adr2].next;
	}
	if (adr2 != -1)
		printf("%05d", adr2);
	else
		cout << "-1";
	system("pause");
	return 0;
}