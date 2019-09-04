#include<iostream>
#include<string>
#include<set>
using namespace std;

int Q1124()
{
	int num, interval, start;
	scanf("%d %d %d\n", &num, &interval, &start);
	set<string> winner;
	if (num < start) {
		cout << "Keep going...";
	}
	else {
		int i = 0;
		string temp;
		while (i++ < start) {
			getline(cin, temp);
		}
		for (i = start; i <= num; i++) {
			if ((i - start) % interval != 0) {
				getline(cin, temp);
				continue;
			}
			if (winner.insert(temp).second == 1)
				cout << temp << endl;
			else{
				while (i++ <= num) {
					if (winner.insert(temp).second == 1) {
						cout << temp << endl;
						start = i;
						break;
					}
					getline(cin, temp);
				}
			}
			if(i <= num)
				getline(cin, temp);
		}
	}
	
	system("pause");
	return 0;
}