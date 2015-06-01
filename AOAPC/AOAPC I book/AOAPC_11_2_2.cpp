/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.12
 * Source:AOAPC I
 * Note:Adjacency list,Dijkstra,Priority_queue
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
const int maxm = 1000;
const int maxn = 200;

int n,m;
int d[maxn];
int first[maxn];
int u[maxm],v[maxm],w[maxm],next[maxm];

typedef pair<int,int> pii;
priority_queue< pii, vector<pii> , greater<pii> > q;

bool done[maxn];

void read_graph(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) first[i] = -1;
	for(int e = 0; e < m; e++)
	{
		scanf("%d%d%d",&u[e],&v[e],&w[e]);
		next[e] = first[u[e]];
		first[u[e]] = e;
	}
}

void Dijkstra(){
	for(int i = 0; i < n; i++) d[i] = (i == 0 ? 0 : INF);
	memset(done,0,sizeof(done));
	q.push(make_pair(d[0],0));
	while(!q.empty()){
		pii u = q.top(); q.pop();
		int x = u.second;
		if(done[x]) continue;
		done[x] = true;
		for(int e = first[x]; e != -1; e = next[e])
			if(d[v[e]] > d[x] + w[e])
			{
				d[v[e]] = d[x] + w[e];
				q.push(make_pair(d[v[e]],v[e]));
			}
	}
}

int main(){
	return 0;
}