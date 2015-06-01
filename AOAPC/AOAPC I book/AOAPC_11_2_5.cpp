/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.12
 * Source:AOAPC I
 * Note:Folyd
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

const int INF = 0x3f3f3f3f;//Folyd中INF容易溢出
const int maxn = 1000;

int n,m;
int d[maxn][maxn];

void init(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
	for(int i = 0; i < m; i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u][v] = w;
	}
}

void Folyd(){
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}

int main(){
	return 0;
}