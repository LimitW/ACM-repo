/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
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

void maintain(int o,int l,int r)
{
	int lc = o*2, rc = o*2 + 1;
	sumv[o] = minv[o] = maxv[o] = 0;
	if(r > l){
		sumv[o] = sumv[lc] + sumv[rc];
		minv[o] = min(minv[lc],minv[rc]);
		maxv[o] = max(maxv[lc],maxv[rc]);
	}
	minv[o] += addv[o];
	maxv[o] += addv[o];
	sumv[o] += addv[o]*(r-l+1);
}

int y1,y2,v;

void update(int o,int l,int r){
	int lc = o*2, rc = o*2 + 1;
	if (y1 <= l && y2 >= r)
		addv[o] += v;
	else
	{
		int m = l + (r-l)/2;
		if(y1 <= m) update(lc,l,m);
		if(y2 > m) update(rc,m+1,r);
	}
	maintain(o,l,r);
}

int _min,_max,_sum;
void query(int o,int l,int r,int add){
	if(y1 <= l && y2 >= r)
	{
		_sum += sumv[o] + add*(r-l+1);
		_min = min(_min,minv[o]+add);
		_max = max(_max,maxv[o]+add);
	}
	else
	{
		int m = l + (r - l) / 2;
		if(y1 <= m) query(o*2,l,m,add+addv[o]);
		if(y2 > m) query(o*2+1,m+1,r,add+addv[o]);
	}
}

int main(){
	return 0;
}