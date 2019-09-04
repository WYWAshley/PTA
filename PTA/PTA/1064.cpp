#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<int> in, level;
void levelorder(int start, int end, int index) {
	if (start > end) return;
	int n = end - start + 1;
	int l = log(n + 1) / log(2); // 除了最后一层的层数
	int leave = n - (pow(2, l) - 1);// 最后一层的叶子节点数
	// pow(2, l - 1) - 1是除了root结点所在层和最后一层外，左子树的结点个数,都比他小
	// pow(2, l - 1) 是l+1层即最底层最多拥有的属于根结点左子树的结点个数
	// min(pow(2, l - 1), leave)是最后一个结点真正拥有的属于根结点左子树上的结点个数
	int root = start + (pow(2, l - 1) - 1) + min((int)pow(2, l - 1), leave); 
	level[index] = in[root];//in[root]就是中序遍历时处于这个位置的数字本身
	levelorder(start, root - 1, 2 * index + 1);
	levelorder(root + 1, end, 2 * index + 2);
}
int Q1064() {
	int n;
	scanf("%d", &n);
	in.resize(n);
	level.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	sort(in.begin(), in.end());
	levelorder(0, n - 1, 0);
	printf("%d", level[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", level[i]);
	return 0;
}