#include<iostream>
#include<string>
#include<vector>
using namespace std;

string reverseString(string str)
{
	if (str.length() <= 1) return str;
	string strLeft = str.substr(0, str.length() / 2);
	string strRight = str.substr(str.length()/2,str.length());
	return reverseString(strRight) + reverseString(strLeft);
}
int Q1001()
{
	int a, b;
	cin >> a >> b;
	int res = a + b;
	if (res < 0)
	{
		cout << "-";
		res = -1 * res;
	}

	string str=to_string(res);
	str = reverseString(str);
	vector<char> v;
	for (int i = 1; i <= str.length(); i++)
	{
		v.push_back(str[i-1]);
		if (i % 3 == 0 && i+1 <= str.length())
			v.push_back(',');
	}
	for (int i = v.size(); i > 0; i--)
	{
		cout << v[i-1];
	}

	getchar(); getchar();
	return 0;
}