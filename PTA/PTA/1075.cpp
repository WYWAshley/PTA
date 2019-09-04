#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct stu
{
	int count, total, id;//正确题目的个数和总分
	vector<int> ans;//每道题目的得分
	bool isRanked;
};

bool cmp(stu s1, stu s2)
{
	if (s1.total != s2.total)
		return s1.total > s2.total;
	else {
		if (s1.count != s2.count)
			return s1.count > s2.count;
		else
			return s1.id < s2.id;
	}
}

int Q1075()
{
	int stu_num, q_num, sub_num;
	scanf("%d %d %d", &stu_num, &q_num, &sub_num);
	vector<stu> v_stu(stu_num + 1);
	for (int i = 1; i < v_stu.size(); i++) {
		v_stu[i].id = i;
		v_stu[i].total = v_stu[i].count = 0;
		v_stu[i].ans.resize(q_num + 1, -2);
	}

	vector<int> v_mark(q_num + 1);
	for (int i = 1; i < q_num + 1; i++)
		scanf("%d", &v_mark[i]);
	for (int i = 0; i < sub_num; i++) {
		int user_id, problem_id, partial_score_obtained;
		scanf("%d %d %d", &user_id, &problem_id, &partial_score_obtained);

		if (partial_score_obtained > v_stu[user_id].ans[problem_id]) {
			if (partial_score_obtained >= 0)
				v_stu[user_id].isRanked = true;
			if (v_stu[user_id].ans[problem_id] > 0)
				v_stu[user_id].total -= v_stu[user_id].ans[problem_id];

			partial_score_obtained = partial_score_obtained < v_mark[problem_id] ? partial_score_obtained : v_mark[problem_id];
			v_stu[user_id].ans[problem_id] = (partial_score_obtained <= -1 ? 0 : partial_score_obtained);

			if (v_stu[user_id].ans[problem_id] == v_mark[problem_id])
				v_stu[user_id].count++;
			v_stu[user_id].total += v_stu[user_id].ans[problem_id];
		}
	}
	sort(v_stu.begin() + 1, v_stu.end(), cmp);
	int rank = 1, cnt = 1;
	for (int i = 1; i < v_stu.size() && v_stu[i].isRanked; i++) {
		if (i > 1) {
			if (v_stu[i].total < v_stu[i - 1].total) {
				rank += cnt;
				cnt = 1;
			}
			else
				cnt++;
		}
		printf("%d %05d %d", rank, v_stu[i].id, v_stu[i].total);
		for (int j = 1; j <= q_num; j++) {
			if (v_stu[i].ans[j] == -2)
				printf(" -");
			else
				printf(" %d", v_stu[i].ans[j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}