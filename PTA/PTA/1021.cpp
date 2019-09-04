#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 10000;
vector<int> G[maxn];
bool  vis[maxn] = { false };
int maxdepth = 0;
int N;
set<int> deepestroots;
void DFS(int u, int depth)
{
	if (maxdepth < depth)
	{
		maxdepth = depth;
		deepestroots.clear();
		deepestroots.insert(u + 1);
	}
	else if (maxdepth == depth)
	{
		deepestroots.insert(u + 1);
	}
	vis[u] = true;
	for (int i = 0; i < G[u].size(); i++)
	{
		int t = G[u][i];
		if (!vis[t])
		{
			DFS(t, depth + 1);
		}
	}
}
void DFSTrave(vector<int>*G)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			DFS(i, 1);
			count++;
		}
	}
	if (count == 1)
	{
		set<int>::iterator it = deepestroots.begin();
		int s = *(it)-1;
		maxdepth = 0;
		fill(vis, vis + maxn, false);
		set<int> deepestrootstemp = deepestroots;
		deepestroots.clear();
		DFS(s, 1);
		it = deepestrootstemp.begin();
		for (it; it != deepestrootstemp.end(); it++)
		{
			deepestroots.insert(*(it));
		}
		it = deepestroots.begin();
		for (it; it != deepestroots.end(); it++)
		{
			printf("%d\n", *it);
		}
	}
	else
	{
		printf("Error: %d components\n", count);
	}
}//只需至少两次DFS就行，若太多会超时，第一次DFS找出深度最大的那些点，然后从中任选一个进行
 //第二次DFS，再次找深度最大的哪些点，这两次DFS所找到的点的并集就是，注意去重和排序
int Q1021()
{
	scanf("%d", &N);
	int u, v;
	if (N == 1)
	{
		printf("1\n");
		return 0;
	}
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &u, &v);
		G[u - 1].push_back(v - 1);
		G[v - 1].push_back(u - 1);
	}
	DFSTrave(G);
	return 0;
}
