#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#define MAXN 500
#define INF 999999
using namespace std;

int cap[MAXN][MAXN], flow[MAXN][MAXN];
int pre[MAXN], res[MAXN];
int Edmonds_Karp(int start, int end)
{
	int maxflow = 0;
	memset(flow, 0, sizeof(flow));
	memset(pre, 0, sizeof(pre));
	queue<int> q;
	while (true)
	{
		memset(res, 0, sizeof(res));
		res[start] = INF;
		q.push(start);
		while (!q.empty()) //BFSѰ������·
		{
			int u = q.front();
			q.pop();
			for (int v = 1; v <= end; v++)
				if (!res[v] && cap[u][v]>flow[u][v])
				{
					res[v] = min(res[u], cap[u][v] - flow[u][v]);//start-v·���ϵ���С����
					pre[v] = u;//��¼v�ĸ��ף������������
					q.push(v);
				}
		}
		for (int u = end; u != start; u = pre[u])//�ӻ��������
		{
			flow[pre[u]][u] += res[end];//����������
			flow[u][pre[u]] -= res[end];//���·�����
		}
		maxflow += res[end]; //���´�s������������
		if (res[end] == 0) return maxflow;//�޷��������������������ǰ���Ѿ��������
	}
}
int T1003() 
{
	map<string, int> id;
	map<int, string> name;
	string start, end;
	int transNum, counter = 1;
	cin >> start >> end >> transNum;
	id[start] = 0;
	name[0] = start;
	for (int i = 0; i < transNum; i++) {
		string tmp1, tmp2;
		int tmpcap;
		cin >> tmp1 >> tmp2 >> tmpcap;
		if (id.find(tmp1) == id.end()) {
			id[tmp1] = counter;
			name[counter] = tmp1;
			counter++;
		}
		if (id.find(tmp2) == id.end()) {
			id[tmp2] = counter;
			name[counter] = tmp2;
			counter++;
		}
		cap[id[tmp1]][id[tmp2]] = tmpcap;
	}
	id[end] = counter;
	name[counter] = end;
	
	cout << Edmonds_Karp(0, counter) << endl;
	system("pause");
	return 0;
}