#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct pos {
	int num, line, column;
	pos(int n, int l, int c) {
		num = n; line = l; column = c;
	}
};
vector<vector<vector<bool>>> flag;
queue<pos> q;
int line, column, num, T, cnt = 0, total = 0;
void BFS() {
	while (!q.empty()) {
		int tmpn = q.front().num;
		int tmpl = q.front().line;
		int tmpc = q.front().column;
		cnt++;
		flag[tmpn][tmpl][tmpc] = 0;
		q.pop();
		if (tmpn != 0 && flag[tmpn - 1][tmpl][tmpc]) {
			flag[tmpn - 1][tmpl][tmpc] = 0;
			q.push({ tmpn - 1, tmpl, tmpc });
		}
		if (tmpn != num - 1 && flag[tmpn + 1][tmpl][tmpc]) {
			flag[tmpn + 1][tmpl][tmpc] = 0;
			q.push({ tmpn + 1, tmpl, tmpc });
		}
		if (tmpl != 0 && flag[tmpn][tmpl - 1][tmpc]) {
			flag[tmpn][tmpl - 1][tmpc] = 0;
			q.push({ tmpn, tmpl - 1, tmpc });
		}
		if (tmpl != line - 1 && flag[tmpn][tmpl + 1][tmpc]) {
			flag[tmpn][tmpl + 1][tmpc] = 0;
			q.push({ tmpn, tmpl + 1, tmpc });
		}
		if (tmpc != 0 && flag[tmpn][tmpl][tmpc - 1]) {
			flag[tmpn][tmpl][tmpc - 1] = 0;
			q.push({ tmpn, tmpl, tmpc - 1 });
		}
		if (tmpc != column - 1 && flag[tmpn][tmpl][tmpc + 1]) {
			flag[tmpn][tmpl][tmpc + 1] = 0;
			q.push({ tmpn, tmpl, tmpc + 1 });
		}
	}
	if (cnt >= T)
		total += cnt;
	cnt = 0;
}
int Q1091()
{
	scanf("%d %d %d %d", &line, &column, &num, &T);
	flag.resize(num);
	for (int i = 0; i < num; i++) {
		flag[i].resize(line);
		for (int j = 0; j < line; j++) {
			flag[i][j].resize(column);
			for (int k = 0; k < column; k++) {
				int d;
				scanf("%d", &d);
				flag[i][j][k] = d;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < line; j++) {
			for (int k = 0; k < column; k++) {
				if (flag[i][j][k]) {
					q.push({ i, j, k });
					BFS();
				}
			}
		}
	}
	printf("%d", total);
	system("pause");
	return 0;
}