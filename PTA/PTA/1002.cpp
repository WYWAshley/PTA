#include<iostream>
#include<vector>
#include<iomanip>
#include<math.h>
#include<cstdio>
using namespace std;

int Q1002() {
	int m, n;
	cin >> m;
	vector<vector<double>> vm(m);
	for (int i = 0; i < m; i++)
	{
		vm[i].resize(2);
		cin >> vm[i][0];
		cin >> vm[i][1];
	}
	cin >> n;
	vector<vector<double>> vn(n);
	for (int i = 0; i < n; i++)
	{
		vn[i].resize(2);
		cin >> vn[i][0];
		cin >> vn[i][1];
	}

	int a=0, b=0;
	vector<vector<double>> res;
	while (a<m && b<n)
	{
		vector<double> tmp(2);
		if (vm[a][0] == vn[b][0])
		{
			tmp[0] = vm[a][0]; 
			tmp[1] = vm[a][1] + vn[b][1];
			if(tmp[1]!=0) res.push_back(tmp);
			a++;
			b++;
			continue;
		}
		if (vm[a][0] > vn[b][0])
		{
			tmp[0] = vm[a][0];
			tmp[1] = vm[a][1];
			if (tmp[1]!=0) res.push_back(tmp);
			a++;
			continue;
		}
		if (vm[a][0] < vn[b][0])
		{
			tmp[0] = vn[b][0];
			tmp[1] = vn[b][1];
			if (tmp[1] != 0) res.push_back(tmp);
			b++;
			continue;
		}
	}
	while (a < m)
	{
		vector<double> tmp(2);
		tmp[0] = vm[a][0];
		tmp[1] = vm[a][1];
		if(tmp[1] != 0) res.push_back(tmp);
		a++;
	}
	while (b < n)
	{
		vector<double> tmp(2);
		tmp[0] = vn[b][0];
		tmp[1] = vn[b][1];
		if (tmp[1] != 0) res.push_back(tmp);
		b++;
	}
	cout << res.size();
	for (int i = 0; i < res.size(); i++)
	{
		cout << " " << res[i][0]<<" ";
		printf("%.1f", res[i][1]);
	}

	getchar();
	getchar();
	return 0;
}