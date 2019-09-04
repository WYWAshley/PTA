#include<iostream>
#include<vector>
using namespace std;

vector<int> pre, post, post_pos, tree;

bool getTree(int pre_s, int pre_e, int post_s, int post_e) {
	if (pre_s > pre_e)
		return false;
	if (pre_s == pre_e) {
		tree.push_back(pre[pre_s]);
		return true;
	}
	// find left child
	int left_c = pre[pre_s + 1];
	int left_c_post_pos = post_pos[left_c];
	int left_c_num = left_c_post_pos - post_s;
	bool haveLeft = getTree(pre_s + 1, pre_s + 1 + left_c_num, post_s, left_c_post_pos);
	//in-order traversal
	tree.push_back(pre[pre_s]);
	// find right child
	bool haveRight = getTree(pre_s + 1 + left_c_num + 1, pre_e, left_c_post_pos + 1, post_e - 1);

	return haveLeft && haveRight;
}
int Q1119()
{
	int num;
	cin >> num;
	pre.resize(num + 1, 0), post.resize(num + 1, 0), post_pos.resize(num + 1, 0);
	for (int i = 1; i <= num; i++) 
		scanf("%d", &pre[i]);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &post[i]);
		post_pos[post[i]] = i;
	}
	bool isUnique = getTree(1, num, 1, num);
	printf("%s\n", (isUnique? "Yes" : "No"));

	for (int i = 0; i < tree.size(); i++) {
		printf("%d", tree[i]);
		if (i < tree.size() - 1)
			printf(" ");
		else
			printf("\n");
	}

	system("pause");
	return 0;
}