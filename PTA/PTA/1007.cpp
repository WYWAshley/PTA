#include<iostream>
#include<vector>
using namespace std;

int Q1007()
{
	int K;
	cin >> K;
	vector<int> v(K);
	for (int i = 0; i < K; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int max = -9999999;
	int m, n;
	for (int i = 0; i < K; i++)
	{
		int tmp = 0;
		for (int j = i; j < K; j++)
		{
			tmp = tmp + v[j];
			if (tmp > max)
			{
				max = tmp; m = i; n = j;
			}
		}
	}
	cout << max << " " << m << " " << n;

	system("pause");
	return 0;
}