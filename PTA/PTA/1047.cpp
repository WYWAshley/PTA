#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

vector<string> name;
bool cmp(int a, int b) {
	return name[a] < name[b];
}
int Q1047()
{
	int stuNum, couNum;
	scanf("%d %d", &stuNum, &couNum);
	vector<vector<int>> res(couNum + 1);
	name.resize(stuNum);
	for (int i = 0; i < stuNum; i++) {
		int n;
		char na[5];
		scanf("%s", &na[0]);
		name[i] = na;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			res[num].push_back(i);
		}
	}
	
	for (int i = 1; i <= couNum; i++) {
		sort(res[i].begin(), res[i].end(), cmp);
		printf("%d %d\n", i, res[i].size());
		for (int j = 0; j < res[i].size(); j++) {
			printf("%s\n", name[res[i][j]].c_str());
		}
	}

	system("pause");
	return 0;
}