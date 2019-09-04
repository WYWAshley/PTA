#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int Q1110()
{
	int num;
	scanf("%d\n", &num);
	vector<bool> vflag;
	vector<int> lchild, rchild;
	vflag.resize(num, false);
	lchild.resize(num, -1);
	rchild.resize(num, -1);
	for (int i = 0; i < num; i++) {
		string s1, s2;
		int c1, c2;
		cin >> s1 >> s2;
		if (s1 != "-") {
			c1 = stoi(s1);
			vflag[c1] = true;
			lchild[i] = c1;
		}
		if (s2 != "-") {
			c2 = stoi(s2);
			vflag[c2] = true;
			rchild[i] = c2;
		}
	}
	int root = -1;
	for (int i = 0; i < num; i++) {
		if (!vflag[i]) {
			root = i;
			break;
		}
	}
	bool canHaveChild = true;
	queue<int> levelTraversal;
	levelTraversal.push(root);
	int tempNum = 1;
	while (canHaveChild && tempNum < num) {
		int nowNode = levelTraversal.front();
		if (lchild[nowNode] == -1) {
			canHaveChild = false;
			break;
		}
		else {
			levelTraversal.push(lchild[nowNode]);
			tempNum++;
		}
		if (rchild[nowNode] == -1) {
			canHaveChild = false;
			break;
		}
		else {
			levelTraversal.push(rchild[nowNode]);
			tempNum++;
		}
		levelTraversal.pop();
	}
	if (tempNum < num)
		printf("NO %d", root);
	else
		printf("YES %d", levelTraversal.back());
	system("pause");
	return 0;
}