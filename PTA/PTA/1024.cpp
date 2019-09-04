#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Reverse(char* num, char* temp, char* res) {
	int flag = 0;
	temp[strlen(num)] = '\0';
	res[strlen(num)] = '\0';
	for (int i= strlen(num)-1, j=0; i>=0; i--,j++)
	{
		temp[j] = num[i];
		int c = num[i]-'0'+ num[j] - '0';
		if (flag > 0) {
			c = c + flag;
			flag = 0;
		}
		if (c >= 10) {
			flag = c / 10;
			c = c % 10;
		}
		res[i] = c+'0';
	}
	if (flag > 0) {
		res[strlen(res) + 1] = '\0';
		for (int i = strlen(res); i >= 1; i--) {
			res[i] = res[i - 1];
		}
		res[0] = flag + '0';
	}
	return;
}

int Q1024()
{
	char number[100],temp[100], res[100];
	int times;
	cin >> number >> times;
	for (int i = 0; i < times; i++)
	{
		Reverse(number, temp, res);
		if (strcmp(number, temp) == 0)
		{
			cout << temp << endl;
			cout << i << endl;
			system("pause");
			return 0;
		}
		strcpy(number, res);
	}
	cout << res << endl;
	cout << times << endl;
	system("pause");
	return 0;
}