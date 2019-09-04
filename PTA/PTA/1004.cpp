#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> child;//���ڼ�¼���ӵĺ���
vector<int> level;//��¼���Ĳ�����root��0
vector<int> num;//���ÿ��Ҷ�ڵ�����
int tmp = 0;//��¼��ǰ����
void countLevelNum(int par, int tmp)
{
	level[par] = tmp;
	if (child[par].size() > 0)//��Ҷ�ڵ�
	{
		tmp -= 1;
		//�ֱ�����ӽڵ�
		for (int i = 0; i < child[par].size(); i++)
		{
			countLevelNum(child[par][i], tmp);
		}
	}
	if (child[par].size() == 0)//��Ҷ�ڵ�
	{
		num[-tmp]++;
		return;
	}
	return;
}
int Q1004()
{
	int N, M;
	cin >> N >> M;
	if (N <= 0) return 0;
	child.resize(N + 1);
	level.resize(N + 1);
	num.resize(N, 0);
	for (int i = 1; i < N + 1; i++)
	{
		level[i] = 0;
	}
	//�������
	for (int i = 0; i < M; i++)
	{
		int par, num;
		cin >> par >> num;
		for (int j = 0; j < num; j++)
		{
			int ctmp;
			cin >> ctmp;
			child[par].push_back(ctmp);
		}
	}

	countLevelNum(1,0);
	int small = 0;
	for (int i = 0; i < N; i++)
	{
		if (small > level[i + 1])
			small = level[i + 1];
	}
	if (num[0] == 0) cout << "0";
	else
	{
		cout << "1";
		return 0;
	}
	for (int i = 1; i <= -small; i++)
	{
		cout << " " << num[i];
	}
	
	system("pause");
	return 0;
}