#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define MAXNUM 10010
int fath[MAXNUM];
int root[MAXNUM];
int getFath(int a) {
	return fath[a] == a ? a : fath[a] = getFath(fath[a]);
}
int Q1118(int argc, char const *argv[])
{
	int picNum, qNum, bNum = 0;
	cin >> picNum;
	for (int i = 1; i <= MAXNUM; i++)
		fath[i] = i, root[i] = 0;
	for (int i = 0; i < picNum; i++) {
		int birNum, first;
		scanf("%d %d", &birNum, &first);
		if (first > bNum)
			bNum = first;
		for (int j = 1; j < birNum; j++) {
			int id;
			scanf("%d", &id);
			if (id > bNum)
				bNum = id;
			fath[getFath(id)] = getFath(first);
		}
	}

	int count = 0;//这个方法比用set快
	for (int i = 1; i <= bNum; i++) {
		int fa = getFath(i);
		root[fa]++;
		if (root[fa] == 1) {
			count++;
		}
	}
	printf("%d %d\n", count, bNum);

	cin >> qNum;
	for (int i = 0; i < qNum; i++) {
		int b1, b2;
		scanf("%d%d", &b1, &b2);
		if (getFath(b1) == getFath(b2))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}