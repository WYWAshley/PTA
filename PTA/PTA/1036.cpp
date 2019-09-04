#include<iostream>
#include<map>
using namespace std;

int Q1036()
{
	int num;
	scanf("%d", &num);
	int high = -1; 
	string fn, fid;
	int low = 101;
	string mn, mid;
	for (int i = 0; i < num; i++) {
		string name, id;
		name.resize(11);
		id.resize(11);
		char sex;
		int grade;
		scanf("%s %c%s%d", &name[0], &sex, &id[0], &grade);
		if (sex == 'F') {
			if (grade > high && grade <= 100) {
				high = grade;
				fn = name;
				fid = id;
			}
		}
		else if (sex == 'M') {
			if (grade < low && grade >= 0) {
				low = grade;
				mn = name;
				mid = id;
			}
		}
	}

	if (high != -1)
		printf("%s %s\n", fn.c_str(), fid.c_str());
	else
		printf("Absent\n");
	if (low != 101)
		printf("%s %s\n", mn.c_str(), mid.c_str());
	else
		printf("Absent\n");
	if (high == -1 || low == 101)
		printf("NA\n");
	else
		printf("%d\n", high - low);
	system("pause");
	return 0;
}