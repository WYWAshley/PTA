#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct record
{
	string name;
	string time1;
	string time2;
};
int timeCompare(string s1, string s2)//1ÊÇs2´ó
{
	for (int i = 0; i < s1.length(); i++)
	{
		if (s2[i] > s1[i])
			return 1;
		else if (s2[i] < s1[i])
			return 0;
	}
}
int Q1006()
{
	int M;
	cin >> M;
	vector<struct record> v(M);
	for (int i = 0; i < M; i++)
	{
		string name, t1, t2;
		cin >> name >> t1 >> t2;
		v[i].name = name;
		v[i].time1 = t1;
		v[i].time2 = t2;
	}
	int latest = 0, earliest = 0;
	for (int i = 0; i < M; i++)
	{
		if (timeCompare(v[i].time2, v[latest].time2) == 0)
			latest = i;
		if (timeCompare(v[i].time1, v[earliest].time1) == 1)
			earliest = i;
	}
	cout << v[earliest].name << " " << v[latest].name;
	system("pause");
	return 0;
}