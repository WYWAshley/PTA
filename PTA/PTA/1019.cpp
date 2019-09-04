#include<iostream>
#include<vector>
using namespace std;

int Q1019()
{
	int n, b;
	cin >> n >> b;
	vector<int> v;
	 do{
		v.push_back(n % b);
		n = n / b;
	 } while (n > 0);
	int size = v.size(), flag = 1;
	for (int i = 0; i < size / 2; i++){
		if (v[i] != v[size - i - 1]) {
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
			cout << v[size - 1 - i] << " ";
		else
			cout << v[0];
	}
	system("pause");
	return 0;
}