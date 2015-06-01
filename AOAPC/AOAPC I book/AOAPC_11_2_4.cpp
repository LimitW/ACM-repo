/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.12
 * Source:AOAPC I
 * Note:SPFA, Bellman-Ford的队列优化
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
const int maxn = 1000;
const int maxm = 4000;

int n,m;
int d[maxn];
int first[maxn];
int u[maxm],v[maxm],w[maxm],next[maxm];

queue<int> q;
bool inq[maxn];

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

void BF(){
	for(int i = 0; i < n; i++) d[i] == (i == 0) ? 0 : INF;
	memset(inq,0,sizeof(inq)); // 在队列中的标志
	q.push(0);
	while(!q.empty()){
		int x = q.front(); q.pop();
		inq[x] = false; //清除“在队列中”标志
		for(int e = first[x]; e != -1; e = next[e])
			if(d[v[e]] > d[x] + w[e]){
				d[v[e]] = d[x] + w[e];
				if(!inq[v[e]]) //如果已在队列中就不重复加了
				{
					inq[v[e]] = true;
					q.push(v[e]);
				}
			}
	}
}
int main(){
	return 0;
}