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
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 1e5+4;

pair<int,int> q[maxn][20];
int pow2[21] , e = 0 ;
map<string,int> mp;
char s[maxn][100];
int head[maxn] , nxt[2*maxn] , v[2*maxn] , pos[maxn];
vector<pair<int,int> > d;

void addEdge(int uu,int vv){
	v[++e] = vv; nxt[e] = head[uu]; head[uu] = e;
}

void dfs(int u , int cur) {
	d.push_back(make_pair(cur,u));
	if(head[u] == -1) pos[u] = (int) d.size() - 1;
	for(int e = head[u]; e != -1; e = nxt[e]){
		dfs(v[e] , cur+1);
		d.push_back(make_pair(cur,u));
		if(pos[u] < 0) pos[u] = (int) d.size() - 1;
	}
}

void RMQ(int n){
	for(int j = 0; pow2[j] < n; j++)
		for(int i = 0; i < n; i++)
		{
			if(j == 0) q[i][j] = d[i];
			else if(i + pow2[j] - 1 < n){
					q[i][j] = min(q[i][j-1] , q[i+pow2[j-1]][j-1]);
			}
			else break;
		}
}

pair<int,int> query(int l,int r) {
	if(l == r) return d[l];
	else {
		for(int i = 20; i >= 0; i--)
			if(pow2[i] == r - l + 1) return q[l][i];
			else if(pow2[i] < r - l + 1) return min(q[l][i] , q[r - pow2[i] +1][i]);
	}
}

int main(){
	pow2[0] =1;
	for(int i = 1; i < 21; i++) pow2[i] = pow2[i-1] * 2;
	memset(head,-1,sizeof(head));
	memset(pos,-1,sizeof(pos));
	int n , m , c = 0; scanf("%d",&n);
	string a,b; char aa[100] , bb[100];
	for(int i = 0; i < n; i++) {
		scanf("%s%s",aa,bb); a = aa; b = bb;
		if(mp.find(a) == mp.end()) { mp[a] = ++c ; strcpy(s[c], aa); }
		if(mp.find(b) == mp.end()) { mp[b] = ++c; strcpy(s[c], bb); }
		addEdge(mp[a],mp[b]);
	}
	dfs(1,1); RMQ(d.size());
	scanf("%d",&m);
	for(int i = 0; i < m; i++) {
		scanf("%s%s",aa,bb); a = aa; b = bb;
		int l = min(pos[mp[a]] , pos[mp[b]]) , r = max(pos[mp[a]],pos[mp[b]]);
		printf("%s\n" , s[query(l , r).second]);
	}
	return 0;
}

