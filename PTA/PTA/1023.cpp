#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

void multiply(char* s, char* res, int (&v)[10])
{
	int size = strlen(s);
	res[size+1] = '\0';
	int flag = 0;
	for (int i = size - 1; i >= 0; i--) {
		int tmp = (s[i] - '0') * 2;
		if (flag > 0) {
			tmp += flag;
			flag = 0;
		}
		if (tmp >= 10) {
			flag = tmp / 10;
			tmp = tmp % 10;
		}
		v[tmp]--;
		res[i+1] = tmp + '0';
	}
	if (flag > 0) {
		v[flag]--;
		res[0] = flag + '0';
	}
	else if (flag == 0) {
		res[0] = '\0';
	}
}
int Q1023() 
{
	char num[25];
	char res[25];
	cin>> num;
	int v[10] = { 0 };
	multiply(num, res, v);
	for (int i = 0; i < strlen(num); i++) {
		v[num[i] - '0'] ++;
	}
	for (int i = 0; i <= 9; i++) {
		if (v[i] != 0) {
			cout << "No" << endl;
			break;
		}
		if (i == 9) {
			cout << "Yes" << endl;
		}
	}
	for (int i = 0; i <= strlen(num); i++) {
		if (res[i] == '\0') 
			continue;
		else 
			cout << res[i];
	}
	system("pause");
	return 0;
}