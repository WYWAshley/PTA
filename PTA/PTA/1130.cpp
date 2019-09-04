#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

struct node {
	int left, right;
	char data[20];
};
void traversal(int root, int depth, const vector<node> &vn) {
	if (root != -1) {
		if (!(depth == 0 || vn[root].left == -1 && vn[root].right == -1))
			printf("(");
		traversal(vn[root].left, depth + 1, vn);
		printf("%s", vn[root].data);
		traversal(vn[root].right, depth + 1, vn);
		if (!(depth == 0 || vn[root].left == -1 && vn[root].right == -1))
			printf(")");
	}

}
int Q1130()
{
	int num;
	scanf("%d", &num);
	vector<struct node> vn(num + 1);
	vector<bool> isRoot(num + 1, true);
	for (int i = 1; i <= num; i++) {
		int l, r;
		char temp[20];
		scanf("%s %d %d", temp, &l, &r);
		strcpy(vn[i].data, temp);
		vn[i].left = l;
		vn[i].right = r;
		if (l != -1)
			isRoot[l] = false;
		if (r != -1)
			isRoot[r] = false;
	}
	int root = -1;
	for (int i = 1; i <= num; i++) {
		if (isRoot[i]) {
			root = i;
			break;
		}
	}
	traversal(root, 0, vn);

	system("pause");
	return 0;
}