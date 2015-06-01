/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.22
 * Source:AOAPC I
 * Note:最短路问题 Dijkstra
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

const int maxn = 100;

int vis[maxn+10];
int w[maxn+10][maxn];

//假设起点为0，到节点i的路径最短路为d[i]

int Dijkstra(){
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < n; i++)
		d[i] = (i == 0 ? 0 : INF);
	for(int i = 0; i < n; i++){
		int x,m = INF;
		for(int y = 0; y < n; y++)
			if(!vis[y] && d[y] <= m)
			{ x = y; m = d[x]; }
		vis[x] = 1;
		for(int y = 0; y < n; y++){
			if(d[y] > d[x] + w[x][y]){
				d[y] = d[x] + w[x][y];
				fa[y] = x;
			}
		}
	}
}

int main(){
	return 0;
}