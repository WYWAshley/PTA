#include<iostream>
#include<vector>
using namespace std;
bool isPrime(int t) {
	if (t == 1)
		return false;
	for (int i = 2; i * i <= t; i++)
		if (t % i == 0)
			return false;
	return true;
}
int Q1078()
{
	int size, num;
	scanf("%d %d", &size, &num);
	while (!isPrime(size))
		size++;
	vector<bool> flag(size, false);
	for (int i = 0; i < num; i++) {
		if (i != 0)
			printf(" ");
		int key;
		scanf("%d", &key);
		bool success = false;
		for (int step = 0; step < size; step++) {
			int index = (key + step * step) % size;
			if (flag[index] == 0) {
				printf("%d", index);
				flag[index] = 1;
				success = 1;
				break;
			}
		}
		if(!success)
			printf("-");
	}
	system("pause");
	return 0;
}
//#include<iostream>
//#include<vector>
//
//using namespace std;
//bool isPrime(int t) {
//	if (t == 1)
//		return true;
//	for (int i = 2; i * i <= t; i++)
//		if (t % i == 0)
//			return false;
//	return true;
//}
//int main()
//{
//	int size, num;
//	scanf("%d %d", &size, &num);
//	while (!isPrime(size))
//		size++;
//	vector<bool> flag(size, false);
//	int first;
//	scanf("%d", &first);
//	printf("%d", first % size);
//	flag[first % size] = 1;
//	for (int i = 1; i < num; i++) {
//		int d;
//		scanf("%d", &d);
//		int cnt = 1, d1 = d, d2 = d;
//		while (flag[d1 % size] && flag[d2 % size] && cnt <= size)
//		{
//			d1 = d + cnt * cnt;
//			d2 = d - cnt * cnt;
//			while (d2 < 0)
//				d2 += size;
//			cnt++;
//		}
//		if (cnt < size) {
//			if (!flag[d1 % size]) {
//				printf(" %d", d1 % size);
//				flag[d1 % size] = 1;
//			}
//			else if (!flag[d2 % size]) {
//				printf(" %d", d2 % size);
//				flag[d2 % size] = 1;
//			}
//		}
//		else
//			printf(" -");
//	}
//	system("pause");
//	return 0;
//}