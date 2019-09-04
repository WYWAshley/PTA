#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct node {
	int val;
	node *left, *right;
};
node *buildtree(node *root, int temp) {
	if (root == NULL) {
		root = new node;
		root->val = temp;
		root->left = root->right = NULL;
	}
	else if (abs(root->val) < abs(temp))
		root->right = buildtree(root->right, temp);
	else
		root->left = buildtree(root->left, temp);
	return root;
}
bool judge1(node *root) {//检查红的小孩是否都是黑的
	if (root == NULL) return true;
	if (root->val < 0) {
		if (root->left != NULL && root->left->val < 0) return false;
		if (root->right != NULL && root->right->val < 0) return false;
	}
	return judge1(root->left) && judge1(root->right);
}
int getNum(node *root) {
	if (root == NULL) return 0;
	int l = getNum(root->left);
	int r = getNum(root->right);
	return root->val < 0? max(l, r) : max(l, r)+1;
}
bool judge2(node *root) {//检查黑节点的个数，相当于是从根节点开始遍历，检查节点的高度
	if (root == NULL) return true;
	int l = getNum(root->left);
	int r = getNum(root->right);
	if (l != r) return false;
	return judge2(root->left) && judge2(root->right);
}
int main() 
{
	int qnum;
	scanf("%d", &qnum);
	for (int i = 0; i < qnum; i++) {
		int num;
		scanf("%d", &num);
		int temp;
		node *root = NULL;
		for (int j = 0; j < num; j++) {
			scanf("%d", &temp);
			root = buildtree(root, temp);
		}
		if (root->val < 0 || !judge1(root) || !judge2(root))
			printf("No\n");
		else
			printf("Yes\n");
	}
	system("pause");
	return 0;
}