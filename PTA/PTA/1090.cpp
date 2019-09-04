#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int maxlevel = 0, cnt = 0;
void DFS(vector<vector<int>> &supp, int root, int level)
{
	if (level > maxlevel) {
		cnt = 1;
		maxlevel = level;
	}
	else if (level == maxlevel)
		cnt++;
	for (int i = 0; i < supp[root].size(); i++)
		DFS(supp, supp[root][i], level + 1);
}

int Q1090()
{
	int num;
	double ini, profit;
	scanf("%d%lf%lf", &num, &ini, &profit);
	vector<vector<int>> supp(num);
	int root;
	for (int i = 0; i < num; i++) {
		int d;
		scanf("%d", &d);
		if (d == -1) 
			root = i;
		else
			supp[d].push_back(i);
	}
	DFS(supp, root, 0);
	printf("%.2lf %d", ini*pow((profit*0.01+1),maxlevel), cnt);
	system("pause");
	return 0;
}