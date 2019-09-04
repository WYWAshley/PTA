#include<iostream>
#include<vector>
#include<map>
using namespace std;

int	Q1045()
{
	int t; cin >> t;
	int colorNum;
	bool choose[201] = {false};
	scanf("%d", &colorNum);
	map<int, int> color;
	vector<int> stripe(colorNum+1, 0);
	for (int i = 0; i < colorNum; i++) {
		int d;
		scanf("%d", &d);
		choose[d] = true;
		color[d] = i + 1;
	}
	int chainNum;
	scanf("%d", &chainNum);
	int cnt = 1;
	for (int i = 0; i < chainNum; i++) {
		int d;
		scanf("%d", &d);
		if (!choose[d])//把不喜欢的颜色直接剔除
			continue;
		else {//stripe数组的123表示的不是喜欢的颜色而是喜欢的颜色的序号
			int sequence = color[d];//这个颜色的喜好序号
			int max = 0;
			for (int i = 1; i <= sequence; i++) {
				if (max < stripe[i] + 1)
					max = stripe[i] + 1;
			}
			stripe[sequence] = max;
		}
	}
	
	int res = 0;
	for (int i = 1; i < stripe.size(); i++) {
		if (res < stripe[i])
			res = stripe[i];
	}
	cout << res;
	system("pause");
	return 0;
}