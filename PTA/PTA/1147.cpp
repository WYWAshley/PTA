#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string ge[9] = { "I","II","III","IV","V","VI","VII","VIII","IX" };
		string shi[9] = { "X","XX","XXX","IL","L","LX","LXX","LXXX","XC" };
		string bai[9] = { "C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
		string qian[3] = { "M","MM","MMM" };
		int degree = 0;
		string res;
		while (num > 0) {
			int now = num % 10;
			num = num / 10;
			if (now == 0)
				continue;
			if (degree == 0) {
				res.insert(0, ge[now - 1]);
			}
			else if (degree == 1) {
				res.insert(0, shi[now - 1]);
			}
			else if (degree == 2) {
				res.insert(0, bai[now - 1]);
			}
			else {
				res.insert(0, qian[now - 1]);
			}
			degree++;
		}
		return res;
	}
};

int main()
{
	Solution s;
	int i;
	cin >> i;
	cout << s.intToRoman(i);
	system("pause");
	return 0;
}