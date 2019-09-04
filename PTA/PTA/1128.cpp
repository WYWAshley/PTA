#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int num;
	scanf("%d\n", &num);
	for (int i = 0; i < num; i++) {
		vector<bool> confi(1005, false), sub(2005, false);
		bool ok = true;
		int cnt;
		scanf("%d", &cnt);
		for (int j = 1; j <= cnt; j++) {
			int temp;
			scanf("%d", &temp);
			if (confi[temp] || sub[temp - j + 1000])
				ok = false;
			confi[temp] = true;
			sub[temp - j + 1000] = true;
		}
		if (ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	system("pause");
	return 0;
}