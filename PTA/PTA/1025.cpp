#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct testee
{
	char num[13];
	int score;
	int local;
	int local_rank;
	int final_rank;
};
bool cmp1(testee t1, testee t2)
{
	if (t1.score > t2.score) return true;
	else if (t1.score == t2.score) {
		for (int i = 0; i < strlen(t1.num) && i < strlen(t2.num); i++) {
			if (t1.num[i] == t2.num[i])
				continue;
			else if (t1.num[i] < t2.num[i])
				return true;
			else return false;
		}
	}
	else return false; 
}
int Q1025()
{
	vector<vector<testee>> v;
	vector<testee> vv;
	int locationNum;
	cin >> locationNum;
	v.resize(locationNum);
	for (int i = 0; i < locationNum; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			testee t;
			cin >> t.num >> t.score;
			t.local = i + 1;
			v[i].push_back(t);
		}
		sort(v[i].begin(),v[i].end(),cmp1);
	}

	for (int i = 0; i < locationNum; i++) {
		int cnt = 1;
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0)
				v[i][j].local_rank = 1;
			else {
				if (v[i][j].score == v[i][j - 1].score) {
					v[i][j].local_rank = v[i][j - 1].local_rank;
					cnt++;
				}
				else {
					v[i][j].local_rank = v[i][j - 1].local_rank + cnt;
					cnt = 1;
				}
			}
			vv.push_back(v[i][j]);
		}
	}
	sort(vv.begin(), vv.end(), cmp1);
	cout << vv.size() << endl;
	int cnt = 1;
	for (int i = 0; i < vv.size(); i++) {
		if (i == 0)
			vv[i].final_rank = 1;
		else {
			if (vv[i].score == vv[i-1].score) {
				vv[i].final_rank = vv[i-1].final_rank;
				cnt++;
			}
			else {
				vv[i].final_rank = vv[i-1].final_rank + cnt;
				cnt = 1;
			}
		}
		printf("%s %d %d %d\n",vv[i].num,vv[i].final_rank,vv[i].local,vv[i].local_rank);
	}

	system("pause");
	return 0;
}