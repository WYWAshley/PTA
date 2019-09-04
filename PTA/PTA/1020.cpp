#include<iostream>
#include<vector>
using namespace std;

int maxlevel = 0;
vector<vector<int>> res;
int search(vector<int> v, int s)
{
	int i;
	for (i = 0; i < v.size(); i++) {
		if (s == v[i]) break;
	}
	return i;
}
void findroot(vector<int> intmp, vector<int> posttmp, int level)
{
	if (maxlevel < level) maxlevel = level;
	int root = posttmp[posttmp.size() - 1];
	res[level].push_back(root);
	int th = search(intmp, root);
	vector<int> lin, rin, lpo, rpo;
	for (int i = 0; i < th; i++) {
		lin.push_back(intmp[i]);
	}
	for (int i = th+1; i < intmp.size(); i++) {
		rin.push_back(intmp[i]);
	}
	for (int i = 0; i < th; i++) {
		lpo.push_back(posttmp[i]);
	}
	for (int i = th; i < th + rin.size(); i++) {
		rpo.push_back(posttmp[i]);
	}
	if(lin.size()>0) 
		findroot(lin, lpo, level+1);
	if(rin.size()>0) 
		findroot(rin, rpo, level+1);
	return;
}
int Q1020()
{
	res.resize(35);
	vector<int> post, in, level;
	int num; cin >> num;
	post.resize(num); in.resize(num);
	for (int i = 0; i < num; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < num; i++) {
		cin >> in[i];
	}
	findroot(in, post, 0);
	for (int i = 0; i <= maxlevel; i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
			if (!(i == maxlevel  && j == res[i].size() - 1))
				cout << " ";
		}
	}
	system("pause");
	return 0;
}