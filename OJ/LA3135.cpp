/************************************************
 * Title:Arugs
 * Author:LimitW
 * Date:2014.10.4
 * Source:LA3135 Beijing 2004
 * Note:priority queue
*************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Item{
	int qnum,period,time;
	bool operator < (const Item & a) const{
		return time > a.time || (time == a.time && qnum > a.qnum);
	}
};

int main(){
	priority_queue<Item> pque;
	char s[20];
	while(scanf("%s",&s) && s[0] != '#')
	{
		Item now;
		scanf("%d%d",&now.qnum,&now.period);
		now.time = now.period;
		pque.push(now);
	}
	int k;
	scanf("%d",&k);
	for(int i = 0; i < k; i++)
	{
		Item r = pque.top();
		pque.pop();
		printf("%d\n",r.qnum);
		r.time += r.period;
		pque.push(r);
	}
	//system("pause");
	return 0;
}