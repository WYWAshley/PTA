#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

int Q1122()
{
	int nodeNum, edgeNum;
	scanf("%d %d", &nodeNum, &edgeNum);
	vector<vector<int>> road(nodeNum + 1);
	set<int> count;
	for (int i = 1; i <= nodeNum; i++) {
		road[i].resize(nodeNum + 1, 0);
	}
	for (int i = 0; i < edgeNum; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		road[n1][n2] = 1;
		road[n2][n1] = 1;
	}
	int qNum;
	scanf("%d", &qNum);
	for (int i = 0; i < qNum; i++) {
		int num;
		string temp;
		scanf("%d", &num);
		if (num != nodeNum + 1) {
			printf("NO\n");
			getline(cin, temp);
			continue;
		}
		int j = 1, s, e, first;
		scanf("%d", &s);
		first = s;
		while (j < num) {
			scanf("%d", &e);
			if (!road[s][e])
				break;
			count.insert(e);
			j++;
			s = e;
		}
		if (j == num && count.size() == nodeNum && first == e || nodeNum == 1)
			printf("YES\n");
		else {
			printf("NO\n");
			getline(cin, temp);//通过break输出错误之后要记得把那一行全部跳过
		}
		count.clear();
	}
	
	system("pause");
	return 0;
}