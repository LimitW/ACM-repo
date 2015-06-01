/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.22
 * Source:AOAPC
 * Note:无根树转有根树
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

const int maxn = 1e6;

int n;
vector<int> G[maxn+10];
int p[maxn+10];

void read_tree(){
	int u,v;
	scanf("%d",&n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

void dfs(int u,int fa){//递归 u为根的子树 u的父亲为fa
	int d = G[u].size();
	for(int i = 0; i < d; i++){
		int v = G[u][i];
		if(v != fa) { p[v] = u; dfs(v,u); }
	}
}

int main(){
	memset(p,0,sizeof(p));
	read_tree();
	int root;
	cin >> root;
	p[root] = -1;
	dfs(root,-1);
	for(int i = 0; i < n; i++)
		printf("%d father: %d\n",i,p[i]);
	system("pause");
	return 0;
}

/*
8
0 1
0 2
0 3
1 4
1 5
5 6
5 7
*/