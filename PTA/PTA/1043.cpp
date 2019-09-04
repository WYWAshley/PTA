#include<iostream>
#include<vector>
#define element int
using namespace std;

void getpost(vector<element> &pre, vector<element> &post, int root, int tail, bool isMirror)
{
	if (root > tail) return;
	int i = root + 1, j = tail;
	if (!isMirror) {
		while (i <= tail && pre[root] > pre[i]) i++;
		while (j > root && pre[root] <= pre[j]) j--;
	}
	else {
		while (i <= tail && pre[root] <= pre[i]) i++;
		while (j > root && pre[root] > pre[j]) j--;
	}
	if (i - j != 1)
		return;
	getpost(pre, post, root + 1, j, isMirror);
	getpost(pre, post, i, tail, isMirror);
	post.push_back(pre[root]);
}
int Q1043()
{
	int num; 
	scanf("%d", &num);
	vector<element> pre(num);
	vector<element> post;
	bool isMirror = false;
	for (int i = 0; i < num; i++) {
		element d;
		cin >> pre[i];
	}
	getpost(pre, post, 0, num - 1, isMirror);
	if (post.size() != num) {
		isMirror = true;
		post.clear();
		getpost(pre, post, 0, num - 1, isMirror);
	}
	if (post.size() != num)
		cout << "NO" << endl;
	else {
		printf("YES\n%d", post[0]);
		for (int i = 1; i < post.size(); i++)
			cout << " " << post[i];
	}
	system("pause");
	return 0;
}