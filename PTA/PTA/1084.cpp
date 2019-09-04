#include<iostream>
#include<string>
using namespace std;

int Q1084()
{
	string correct, wrong, wornout;
	getline(cin, correct);
	getline(cin, wrong);
	int i = 0, j = 0;
	for (; i < correct.length(); i++) {
		if (correct[i] == wrong[j]) {
			j++;
			continue;
		}
		char c = correct[i];
		if (isalpha(c))
			c = toupper(c);
		if(wornout.find(c) == std::string::npos)
			wornout += c;
	}
	printf("%s\n", wornout.c_str());
	system("pause");
	return 0;
}