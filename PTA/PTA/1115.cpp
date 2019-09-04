#include<iostream>
#define MAXNUM 1005
using namespace std;
struct node {
	node* lchild;
	node* rchild;
	int val, level;
	node(int v, int l) {
		lchild = rchild = NULL;
		level = l;
		val = v;
	};
};
int cnt[MAXNUM] = { 0 };
void insert(node *&root, int &tmp, int level) {
	if (root == NULL) {
		root = new node(tmp, level);
		cnt[level]++;
		return;
	}
	if (tmp <= root->val) {
		insert(root->lchild, tmp, level+1);
	}
	else {
		insert(root->rchild, tmp, level+1);
	}
}
int Q1115()
{
	node *root = NULL;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		insert(root, tmp, 0);
	}
	for (int i = 0; i < 1005; i++) {
		if (cnt[i] == 0) {
			printf("%d + %d = %d", cnt[i - 1], cnt[i - 2], cnt[i - 1]+cnt[i - 2]);
			break;
		}
	}
	system("pause");
	return 0;
}