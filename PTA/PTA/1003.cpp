#include<iostream>
#include<vector>
#define MAX 999999
using namespace std;

int CityNum, RoadNum, c1, SaveCity;
vector<int> SecureNum;
vector<vector<int>> len;
vector<bool> flag;
int sum = 0;
int shortest = MAX;
int num_Path = 0;
int maxNum = 0;

void DFS(int Nowcity,int dis,int sum)
{
	flag[Nowcity] = true;
	sum += SecureNum[Nowcity];
	//如果找到了SaveCity
	if (Nowcity == SaveCity)
	{
		if (dis == shortest)//确定是最短路径
		{
			num_Path++;
			if (maxNum < sum) maxNum = sum;
		}
		if (dis < shortest)
		{
			num_Path = 1;
			maxNum=sum;
			shortest = dis;
		}
	}
	else
	{
		for (int i = 0; i < CityNum; i++)
		{
			if (flag[i] == false && len[i][Nowcity]<MAX)//如果不在这条路径中
			{
				DFS(i,dis+len[i][Nowcity],sum);
			}
		}
	}
	flag[Nowcity] = false;
}
int Q1003()
{
	cin >> CityNum >> RoadNum >> c1 >> SaveCity;
	SecureNum.resize(CityNum);
	for (int i = 0; i < CityNum; i++)
	{
		cin >> SecureNum[i] ;
	}
	len.resize(CityNum);
	//道路全部初始化为MAX
	for (int i = 0; i < CityNum; i++)
	{
		len[i].resize(CityNum);
		for (int j = 0; j < CityNum; j++)
		{
			if (i == j) len[i][j] = 0;
			else len[i][j] = MAX;
		}
	}
	for (int i = 0; i < RoadNum; i++)
	{
		int c1, c2, l;
		cin >> c1 >> c2 >> l;
		len[c1][c2] = l;
		len[c2][c1] = l;
	}
	flag.resize(CityNum);
	for (int i = 0; i < CityNum; i++)
	{
		flag[i] = false;//表示未该条路径中出现
	}
	DFS(c1, 0, 0);
	
	cout << num_Path << " " << maxNum;

	getchar(); getchar();
	return 0;
}