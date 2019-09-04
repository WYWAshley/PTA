#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void isPrime(vector<int> &q)
{
	q.push_back(2);
	for (int i = 3; i < 500000; i += 2) {
		for (int j = 0; j < q.size(); j++) {
			if (q[j] > sqrt(i)) {
				q.push_back(i);
				break;
			}
			else {
				if (i % q[j] == 0)
					break;
			}
		}
	}
}

int Q1059()
{
	long int n;
	cin >> n;
	long int b = n;
	vector<int> q;
	vector<int> res;
	isPrime(q);
	while (n != 1) {
		for (int i = 0; i < q.size(); i++) {
			if (n%q[i] == 0) {
				res.push_back(q[i]);
				n = n / q[i];
				break;
			}
		}
	}
	printf("%d=", b);
	if (b == 1) {
		printf("1");
		system("pause");
		return 0;
	}
	int cnt = 0, tmp = 1;
	while (cnt < res.size()) {
		if (cnt == 0) {
			printf("%d", res[cnt]);
		}
		else {
			if (res[cnt - 1] == res[cnt]) {
				tmp++;
			}
			else {
				if (tmp > 1) {
					printf("^%d", tmp);
					tmp = 1;
				}
				printf("*%d", res[cnt]);
			}
		}
		cnt++;
	}
	if (tmp > 1)
		printf("^%d",tmp);
	system("pause");
	return 0;
}