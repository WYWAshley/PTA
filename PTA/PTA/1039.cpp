#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int hashName(string name) {
	return (name[0] - 'A') * 26 * 26 * 10\
		+ (name[1] - 'A') * 26 * 10\
		+ (name[2] - 'A') * 10\
		+ (name[3] - '0');
}

int Q1039()
{
	map<int, set<int>> stu_list;
	int stunum, cournum;
	cin >> stunum >> cournum;
	for (int i = 0; i < cournum; i++) {
		int index, n;
		cin >> index >> n;
		for (int j = 0; j < n; j++) {
			string s;
			cin >> s;
			int tmp = hashName(s);
			stu_list[tmp].insert(index);
		}
	}
	for (int i = 0; i < stunum; i++) {
		string name;
		cin >> name;
		int tmp = hashName(name);
		cout << name;
		if (stu_list.find(tmp) == stu_list.end())
			cout << " 0" << endl;
		else {
			int size = stu_list[tmp].size();
			cout << " " << size;
			for (auto it = stu_list[tmp].begin(); it != stu_list[tmp].end(); it++) {
				cout << " " << *it;
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}