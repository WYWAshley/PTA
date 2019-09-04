#include<iostream>
#include<vector>
using namespace std;

typedef struct treeNode {
	int val;
	treeNode *left, *right;
	treeNode(int v, treeNode* l, treeNode* r) { val = v; left = l; right = r; }
}tree;
void buildTree(int now, tree *&root, vector<int> &father, int last, vector<int> &level, int l) {
	if (root == nullptr) {
		root = new treeNode(now, nullptr, nullptr);
		father[root->val] = last;
		level[root->val] = l;
		return;
	}
	else if (root->val > now)
		buildTree(now, root->left, father, root->val, level, l + 1);
	else
		buildTree(now, root->right, father, root->val, level, l + 1);
}
int Q1143()
{
	int nN, nQ;
	scanf("%d %d", &nQ, &nN);
	vector<int> father(nN + 1), level(nN + 1, 0);
	tree *root = nullptr;
	for (int i = 0; i<nN; i++) {
		int temp;
		cin >> temp;
		buildTree(temp, root, father, 0, level, 0);
	}
	for (int i = 0; i<nQ; i++) {
		int t1, t2;
		cin >> t1 >> t2;

		if ((t1 > nN || t1 < 1) && (t2 > nN || t2 < 1)) {
			printf("ERROR: %d and %d are not found.\n", t1, t2);
			continue;
		} 
		else if ((t1 > nN || t1 < 1) && !(t2 > nN || t2 < 1)) {
			printf("ERROR: %d is not found.\n", t1);
			continue;
		}
		else if (!(t1 > nN || t1 < 1) && (t2 > nN || t2 < 1)){
			printf("ERROR: %d is not found.\n", t2);
			continue;
		}
		
		int tt1 = t1, tt2 = t2;//存储最后在同一层的两个数（可能换过了）
		bool overturn = false;//判断tt1与tt2有没有互换
		if (level[t1] != level[t2]) {//使两节点到达同等深度
			if (level[t1] < level[t2]) {
				int temp;
				temp = t1; t1 = t2; t2 = temp;//使得左边的结点比较深
				tt1 = t1, tt2 = t2;
				overturn = true;
			}
			int minus = level[t1] - level[t2];
			for (int j = 0; j<minus; j++) {
				t1 = father[t1];
			}
		}
		if (t1 == t2) {
			printf("%d is an ancestor of %d.\n", tt2, tt1);
		}
		else {
			int minus = level[t2];
			while (minus > 0 && t1 != t2) {
				t1 = father[t1];
				t2 = father[t2];
				minus--;
			}
			if (overturn) {
				int temp = tt1; tt1 = tt2; tt2 = temp;
			}
			printf("LCA of %d and %d is %d.\n", tt1, tt2, t1);
		}
	}
	system("pause");
	return 0;
}