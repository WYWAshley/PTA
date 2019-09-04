#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int leftSon[50], rightSon[50];
vector<int> in, post, res;
map<int, int> m_in, m_post;
int root;
struct node {
	int value;
	node *left, *right;
};
void buildTree(int &r, int in_s, int in_e, int post_s, int post_e) {
	//用引用的方法赋值孩子，注意是在inorder中的位置
	if (in_s > in_e || post_s > post_e)
		return;
	int root = post[post_e];
	int root_loc = m_in[root];
	r = root_loc;
	buildTree(leftSon[r], in_s, root_loc-1, post_s, post_s+root_loc-in_s-1);
	buildTree(rightSon[r], root_loc+1, in_e, post_s+root_loc-in_s, post_e-1);
}
void traversal(queue<int> &q, bool reverse) {
	queue<int> q2;
	while (!q.empty()) {
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (leftSon[now])
				q2.push(leftSon[now]);
			if (rightSon[now])
				q2.push(rightSon[now]);
		}
		q = q2;
		if (reverse) {
			vector<int> v;
			while (!q2.empty()) {
				v.push_back(q2.front());
				q2.pop();
			}
			for (int i = v.size() - 1; i >= 0; i--)
				res.push_back(v[i]);
		}
		else {
			while (!q2.empty()) {
				res.push_back(q2.front());
				q2.pop();
			}
		}
		reverse = !reverse;
	}
}
int Q1127()
{
	int num;
	scanf("%d", &num);
	in.resize(num+1), post.resize(num+1);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &in[i]);
		m_in[in[i]] = i;
	}
	for (int i = 1; i <= num; i++) {
		scanf("%d", &post[i]);
		m_post[post[i]] = i;
	}
	
	buildTree(root, 1, num, 1, num);
	queue<int> q;
	q.push(root);
	res.push_back(root);
	traversal(q, false);

	printf("%d", in[res[0]]);
	for (int i = 1; i < res.size(); i++)
		printf(" %d", in[res[i]]);
	system("pause");
	return 0;
}