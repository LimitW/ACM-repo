#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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

#define LL long long
#define pii pair<int,int>

const int maxn = 2e5 + 3;

vector<pii> a;
vector<int> p;
map<int,int> mp;

struct node {
	int l , r , lazy;
}st[maxn*4];

void pushdown(int o){
	if(!st[o].lazy) return;
	st[o*2].lazy = st[o*2+1].lazy = st[o].lazy;
	st[o].lazy = 0;
}

void build(int l,int r,int o){
	st[o].l = l , st[o].r = r , st[o].lazy = 0;
	if(l + 1 ==  r) return;
	int mid = (l + r) / 2;
	build(l,mid,o*2);
	build(mid,r,o*2+1);
}

void update(int l, int r,int v,int o) {
	if(st[o].l >= l && st[o].r <= r){
		st[o].lazy = v; return;
	}
	pushdown(o);
	int mid = (st[o].l + st[o].r) / 2;
	if(l >= mid) update(l,r,v,o*2+1);
	else if(r <= mid) update(l,r,v,o*2);
	else {
		update(l,mid,v,o*2);
		update(mid,r,v,o*2+1);
	}
}

void query(int o){
	if(st[o].l + 1 == st[o].r){
		if(st[o].lazy != 0)
			p.push_back(st[o].lazy);
		return;
	}
	pushdown(o);
	query(o*2);
	query(o*2+1);
}

int main(){
	int n , L; scanf("%d%d",&n,&L);
	for(int i = 0; i < n; i++){
		int u , v; scanf("%d%d",&u,&v);
		a.push_back(make_pair(u,v));
		p.push_back(u); p.push_back(v);
	}
	sort(p.begin(),p.end());
	n = unique(p.begin(),p.end()) - p.begin();
	for(int i = 0; i < n; i++) mp[p[i]] = i+1;
	build(1,n,1);
	for(int i = 0; i < a.size(); i++){
		int l = mp[a[i].first] , r = mp[a[i].second];
		update(l,r,i+1,1);
	}
	p.clear(); query(1);
	sort(p.begin(),p.end());
	n = unique(p.begin(),p.end()) - p.begin();
	printf("%d\n",n);
	return 0;
}

