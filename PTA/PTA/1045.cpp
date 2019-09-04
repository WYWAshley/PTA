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
		if (!choose[d])//�Ѳ�ϲ������ɫֱ���޳�
			continue;
		else {//stripe�����123��ʾ�Ĳ���ϲ������ɫ����ϲ������ɫ�����
			int sequence = color[d];//�����ɫ��ϲ�����
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