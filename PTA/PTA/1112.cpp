#include<iostream>
#include<vector>
#include<string>
using namespace std;

int Q1112()
{
	int k;
	scanf("%d", &k);
	bool flag[127] = {false};
	string str, ans;
	cin >> str;
	int cnt = 1;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == str[i - 1])
			cnt++;
		else {
			if (cnt%k == 0) {
				if (!flag[str[i - 1]]) {
					flag[str[i - 1]] = 1;
					ans += str[i - 1];
				}
			}
			else
				flag[str[i - 1]] = 0;
			cnt = 1;
		}
	}
	//��������ĩβ��ͬ�ģ�����ѭ���ͻᵼ��ĩβ����û�мӽ�ȥ
	if (cnt%k == 0) {
		if (!flag[str[str.size() - 1]]) {
			flag[str[str.size() - 1]] = 1;
			ans += str[str.size() - 1];
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		if (flag[ans[i]])
			printf("%c", ans[i]);
	}
	for (int i = 0; i < str.size(); i++) {
		if (flag[str[i]])
			str.erase(i, k-1);
	}
	printf("\n%s", str.c_str());
	system("pause");
	return 0;
}