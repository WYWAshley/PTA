#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>
using namespace std;
class BiNode {
public:
	char data;
	struct BiNode *lchild, *rchild;
};
class BiTree {
public:
	BiNode * root;
	int height;
	BiTree() { 
		root = NULL; 
		height = 0; 
	}
	void createBiTree(vector<int> v);
	void preOrder();
	void deletenode(int d);
};
int Q1057()
{
	int cnum;
	stack<int> s;
	scanf("%d", &cnum);
	for (int i = 0; i < cnum; i++) {
		string str;
		cin >> str;
		if (str == "Push") {
			int t;
			scanf("%d", &t);
			s.push(t);
		}
		else if (str == "Pop") {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}
			else
				printf("Invalid\n");
		}
		else (str == "PeekMedian") {
			if (!s.empty())
				printf("%d\n", findMedian(s));
			else
				printf("Invalid\n");
		}
	}

	system("pause");
	return 0;
}


void BiTree::preOrder()
{
}

void BiTree::deletenode(int d)
{
}
