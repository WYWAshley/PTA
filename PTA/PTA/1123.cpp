#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;

struct treeNode
{
	int value;
	treeNode *left, *right;
};
int getHeight(treeNode *tree) {
	if (tree == NULL)
		return 0;
	else {
		int l = getHeight(tree->left);
		int r = getHeight(tree->right);
		return max(l, r) + 1;
	}
}
treeNode *LLRotate(treeNode *tree) {
	treeNode *temp = tree->left;
	tree->left = temp->right;
	temp->right = tree;
	return temp;
}
treeNode *RRRotate(treeNode *tree) {
	treeNode *temp = tree->right;
	tree->right = temp->left;
	temp->left = tree;
	return temp;
}
treeNode *LRRotate(treeNode *tree) {
	tree->left = RRRotate(tree->left);
	return LLRotate(tree);
}
treeNode *RLRotate(treeNode *tree) {
	tree->right = LLRotate(tree->right);
	return RRRotate(tree);
}
treeNode* insertNode(int key, treeNode *tree) {
	if (tree == NULL) {
		tree = new treeNode();
		tree->value = key;
	}
	else if (tree->value > key) {
		tree->left = insertNode(key, tree->left);
		int l = getHeight(tree->left), r = getHeight(tree->right);
		if (l - r >= 2) {
			if (key < tree->left->value)
				tree = LLRotate(tree);
			else
				tree = LRRotate(tree);
		}
	}
	else {
		tree->right = insertNode(key, tree->right);
		int l = getHeight(tree->left), r = getHeight(tree->right);
		if (r - l >= 2) {
			if (key < tree->right->value)
				tree = RLRotate(tree);
			else
				tree = RRRotate(tree);
		}
	}
	return tree;
}
void levelorder(queue<treeNode*> &q, vector<int> &level, bool &flag, bool &isComplete) {
	while (!q.empty()) {
		treeNode* temp = q.front();
		level.push_back(temp->value);
		q.pop();
		if (temp->left == NULL) //flag用来登记是否已经出现了一个没有子节点的节点,1
			flag = 1;
		else {
			q.push(temp->left);
			if (flag == 1)
				isComplete = false;
		}
		if (temp->right == NULL)
			flag = 1;
		else {
			q.push(temp->right);
			if (flag == 1)
				isComplete = false;
		}
	}
}
int Q1123()
{
	int num;
	cin >> num;
	treeNode *tree = NULL;
	for (int i = 0; i < num; i++) {
		int t;
		cin >> t;
		tree = insertNode(t, tree);
	}
	vector<int> level;
	queue<treeNode*> q;
	q.push(tree);
	bool flag = 0, isComplete = 1;
	levelorder(q, level, flag, isComplete);
	cout << level[0];
	for (int i = 1; i < level.size(); i++)
		cout << " " << level[i];
	cout << endl;
	if (isComplete)
		cout << "YES";
	else
		cout << "NO";
	system("pause");
	return 0;
}