#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string DAY[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
bool flag[256] = {false};
int Q1061()
{
	string s1, s2, s3, s4;
	int day = -1, hour = -1, minute = -1;
	cin >> s1 >> s2 >> s3 >> s4;
	int min1 = min(s1.size(), s2.size());
	int min2 = min(s3.size(), s4.size());
	int i = 0;
	for (i; i < min1; i++) {
		if (s1[i] == s2[i] && s1[i] <= 'G' && s1[i] >= 'A') {
			day = s1[i] - 'A';
			break;
		}
	}
	for (i++; i < min1; i++) {
		if (s1[i] == s2[i]) {
			if (s1[i] <= 'N' && s1[i] >= 'A') {
				hour = s1[i] - 'A' + 10;
				break;
			}
			else if (isdigit(s1[i])) {
				hour = s1[i] - '0';
				break;
			}
		}
	}
	for (i = 0; i < min2; i++) {
		if (s3[i] == s4[i] && isalpha(s3[i])) {
			minute = i;
			break;
		}
	}
	printf("%s %02d:%02d", DAY[day].c_str(), hour, minute);
	system("pause");
	return 0;

}