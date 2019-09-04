#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;

int nowtime = 0;
struct customer
{
	int arrive;
	int playtime;
	int wait = 0;
	bool isVIP = false;
	int cusnum;
};
struct table
{
	int residue = 0;
	int tnum;
	bool special = false;
	int avaliable = 0;
};
bool cmp1(customer c1, customer c2)
{
	return c1.arrive < c2.arrive;
}
bool cmp2(table t1, table t2)
{
	t1.avaliable = t1.residue - nowtime >= 0 ? t1.residue - nowtime : 0;
	t2.avaliable = t2.residue - nowtime >= 0 ? t2.residue - nowtime : 0;
	if (t1.avaliable < t2.avaliable) return true;
	else if (t1.avaliable > t2.avaliable) return false;
	else return t1.tnum < t2.tnum;
}
bool cmp3(customer c1, customer c2)
{
	return c1.arrive + c1.wait < c2.arrive + c2.wait;
}
int Q1026()
{
	int cuscnt;
	cin >> cuscnt;
	vector<customer> v;
	for (int i = 0; i < cuscnt; i++) {
		int hh, mm, ss, is;
		customer c;
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&c.playtime,&is);
		c.arrive = (hh - 8) * 3600 + mm * 60 + ss;
		if (!(c.arrive > 13 * 3600 || c.arrive < 0)) {
			if (c.playtime > 2 * 3600)
				c.playtime = 2 * 3600;
			if (is == 1) c.isVIP = true;
			v.push_back(c);
		}
	}
	sort(v.begin(),v.end(),cmp1);
	for (int i = 0; i < v.size(); i++)
		v[i].cusnum = i;
	int tablecnt, viptablecnt;//初始化桌子
	cin >> tablecnt >> viptablecnt;
	vector<table> t;
	for (int i = 1; i <= tablecnt; i++) {
		table ta;
		ta.tnum = i;
		t.push_back(ta);
	}
	for (int i = 0; i < viptablecnt; i++) {
		int num;
		cin >> num;
		t[num-1].special = true;
	}

	int count = 0;//记录一共处理的人数
	int count2 = 0;//记录一共入队的人数
	queue<customer> normal;//记录队伍里面的普通顾客
	queue<customer> special;//记录队伍里面的VIP
	vector<int> servecnt(tablecnt + 1, 0);//记录每张桌子服务人数
	while(count < cuscnt)
	{
		if (normal.empty() && special.empty()) {//没有正在排队的顾客，先入队
			nowtime = v[count2].arrive > nowtime? v[count2].arrive : nowtime;
			if (nowtime >= 13 * 3600) break;
			for (int i = count2; i < v.size(); i++) {
				if (v[i].arrive > nowtime) break;
				else {
					if (v[i].isVIP == true) {
						special.push(v[i]); 
						count2++;
					}
					else {
						normal.push(v[i]); 
						count2++;
					}
				}
			}
		}
		else {//有正在排队的
			sort(t.begin(), t.end(), cmp2);//将桌子进行排序
			if (t[0].residue > nowtime) {
				nowtime = t[0].residue;//第一个空闲的桌子的时间
				sort(t.begin(), t.end(), cmp2);//将桌子进行排序
				for (int i = count2; i < v.size(); i++) {//更新时间再次入队
					if (v[i].arrive > nowtime) break;
					else {
						if (v[i].isVIP == true) { 
							special.push(v[i]); 
							count2++;
						}
						else {
							normal.push(v[i]); 
							count2++;
						}
					}
				}
				sort(t.begin(), t.end(), cmp2);//将桌子进行排序
			}
			if (nowtime >= 13 * 3600) break;
			int getVIPTable = -1;
			for (int i = 0; i < tablecnt; i++) {//找到第一个空着的VIPtable
				if (t[i].special == true && nowtime >= t[i].residue) {
					getVIPTable = i;
					break;
				}
			}
			if (!special.empty() && getVIPTable != -1) {//分配到第一个VIPtable
				t[getVIPTable].residue = nowtime + special.front().playtime*60;
				servecnt[t[getVIPTable].tnum]++;
				v[special.front().cusnum].wait = nowtime - special.front().arrive;
				count++;
				special.pop();
			}
			else if ((!special.empty() && normal.empty()) || (!special.empty() && !normal.empty() && special.front().arrive < normal.front().arrive)) {
				t[0].residue = nowtime + special.front().playtime*60;
				servecnt[t[0].tnum]++;
				v[special.front().cusnum].wait = nowtime - special.front().arrive;
				count++;
				special.pop();
			}
			else {
				t[0].residue = nowtime + normal.front().playtime*60;
				servecnt[t[0].tnum]++;
				v[normal.front().cusnum].wait = nowtime - normal.front().arrive;
				count++;
				normal.pop();
			}
		}
	}
	sort(v.begin(), v.begin()+count, cmp3);
	for (int i = 0; i < count; i++) {
		printf("%02d:%02d:%02d",v[i].arrive/3600+8,(v[i].arrive%3600)/60,v[i].arrive%60);
		int w = floor(v[i].wait*1.0 / 60 + 0.5);
		printf(" %02d:%02d:%02d %d\n", (v[i].arrive+v[i].wait)/3600+8,((v[i].arrive+v[i].wait)%3600)/60,(v[i].arrive+v[i].wait)%60,w);
	}
	cout << servecnt[1];
	for (int i = 2; i <= tablecnt; i++) {
		cout << " " << servecnt[i];
	}
	system("pause");
	return 0;
}