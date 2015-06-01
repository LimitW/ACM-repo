/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.12
 * Source:AOAPC I
 * Note:最大流 增广路 Edmonds-Karp
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

int n;
int flow[200][200],cap[200][200];
int a[200],p[200];
int s,t;
int f;

int EK(){
	queue<int> q;
	memset(flow,0,sizeof(flow));
	f = 0;
	for(;;){
		memset(a,0,sizeof(a));
		a[s] = INF;
		q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int v = 1; v <= n; v++)
				if(!a[v] && cap[u][v] > flow[u][v])
				{
					p[v] = u; q.push(v);
					a[v] = min(a[u],cap[u][v]-flow[u][v]);
				}
		}
		if(a[t] == 0) break;
		for(int u = t; u != s; u = p[u])
		{
			flow[p[u]][u] += a[t];
			flow[u][p[u]] -= a[t];
		}
		f += a[t];
	}
	return f;
}

int main(){
	return 0;
}