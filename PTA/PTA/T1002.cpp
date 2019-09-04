#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<math.h>
using namespace std;

struct project {
	int profit, last, ddl;
	void input() { scanf("%d %d %d", &profit, &last, &ddl); }
	bool operator<(project &p) { return ddl < p.ddl; }
};
int QT1002()
{
	int proNum;
	scanf("%d", &proNum);
	vector<project> vp(proNum);
	for (int i = 0; i < proNum; i++) {
		vp[i].input();
	}
	sort(vp.begin(), vp.end());

	map<int, int> vprofit[52];//�൱����52�еı��
	vprofit[0][0] = 0;
	int maxres= 0 ;
	for (int i = 0; i < proNum; i++)
	{
		vprofit[i + 1] = vprofit[i];//����һ����
		std::map<int, int>::iterator it; //it��first��ʱ�䣬second������
		for (it = vprofit[i].begin(); it != vprofit[i].end(); it++)
		{
			if (it->first + vp[i].last <= vp[i].ddl)
			{
				if(vprofit[i + 1][it->first + vp[i].last] < it->second + vp[i].profit)
					vprofit[i + 1][it->first + vp[i].last] = it->second + vp[i].profit;
				maxres = max(maxres, vprofit[i + 1][it->first + vp[i].last]);
			}
		}
	}
	cout << maxres;
	system("pause");
	return 0;
}