/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.12
 * Source:AOAPC I
 * Note:最小费用最大流 总流量最大的前提下最小费用
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
const int maxn = 200;

int n;
int flow[maxn][maxn],cap[maxn][maxn],cost[maxn][maxn];
int d[maxn],p[maxn];
int s,t;
int f,c;

void solve(){
	queue<int> q;
	int d[200];
	memset(flow,0,sizeof(flow));
	c = f = 0;
	for(;;){
		bool inq[maxn];
		for(int i = 0; i < n; i++)
			d[i] = (i == s ? 0 : INF);
		memset(inq,0,sizeof(inq));
		q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
			inq[u] = false;
			for(int v = 0; v < n; v++)
				if(cap[u][v] > flow[u][v] && d[v] > d[u] + cost[u][v])
				{
					d[v] = d[u] + cost[u][v];
					p[v] = u;
					if(!inq[v])
					{
						inq[v] = true;
						q.push(v);
					}
				}
		}
		if(d[t] == INF) break;
		int a = INF;
		for(int u = t; u != s; u = p[u])
			a = min(a,cap[p[u]][u]-flow[p[u]][u]);
		for(int u = t; u != s; u = p[u]){
			flow[p[u]][u] += a;
			flow[u][p[u]] -= a;
		}
		c += d[t]*a;
		f += a;
	}
}

int main(){
	return 0;
}