#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

vector<int> pre, in, post;
void postorder(int root, int start, int end) {
	if (start > end)
		return;
	int i = start;
	while (i < end && in[i] != pre[root]) 
		i++;
	postorder(root + 1, start, i - 1);
	postorder(root + 1 + i - start, i + 1, end);
	post.push_back(pre[root]);
}
int Q1086()
{
	int num;
	scanf("%d\n", &num);
	stack<int> stack;
	while (in.size() < num)
	{
		string str;
		getline(cin, str);
		if (str[1] == 'u') {
			pre.push_back(stoi(str.substr(5)));
			stack.push(stoi(str.substr(5)));
		}
		else {
			in.push_back(stack.top());
			stack.pop();
		}
	}
	postorder(0, 0, num-1);
	printf("%d", post[0]);
	for (int i = 1; i < num; i++)
		printf(" %d", post[i]);
	system("pause");
	return 0;
}