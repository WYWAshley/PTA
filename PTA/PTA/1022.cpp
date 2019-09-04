#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

void query(map<string, set<int>> &m, string &str)
{
	if (m.find(str) != m.end()) {
		for (auto it = m[str].begin(); it != m[str].end(); it++)
			printf("%07d\n", *it);
	}
	else
		cout << "Not Found"<<endl;
}
map<string, set<int>> title, author, keywords, publisher, year;
int Q1022()
{
	int bookNum, id = 0;
	cin >> bookNum;
	for (int i = 0; i < bookNum; i++) {
		scanf("%d\n", &id);
		string tmptitle, tmpauthor, tmpkey, tmppublisher, tmpyear;
		getline(cin, tmptitle);
		title[tmptitle].insert(id);
		getline(cin, tmpauthor);
		author[tmpauthor].insert(id);
		while (cin >> tmpkey) {
			keywords[tmpkey].insert(id);
			char c = getchar();
			if (c == '\n') break;
		}
		getline(cin, tmppublisher);
		publisher[tmppublisher].insert(id);
		getline(cin, tmpyear);
		year[tmpyear].insert(id);
	}

	int qnum;
	cin >> qnum;
	int q;
	for (int i = 0; i < qnum; i++) {
		scanf("%d: ",&q);
		string str;
		getline(cin, str);
		cout << q << ": " << str << endl;
		if (q == 1) query(title, str);
		if (q == 2) query(author, str);
		if (q == 4) query(publisher, str);
		if (q == 5) query(year, str);
		if (q == 3) query(keywords, str);
	}
	system("pause");
	return 0;
}