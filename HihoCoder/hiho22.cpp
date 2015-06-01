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

const int maxn = 1e5 + 3;

int a[maxn];

struct node {
	int l , r , val , add , set;
}st[maxn*4];

void pushup(int o){
	st[o].val = st[o*2].val + st[o*2+1].val;
}

void pushdown(int o){
	if(st[o].set != -1){
		st[o*2].set = st[o*2+1].set = st[o].set;
		st[o*2].add = st[o*2+1].add = 0;
		st[o].set = -1;
		st[o*2].val = (st[o*2].r - st[o*2].l + 1) * st[o*2].set;
		st[o*2+1].val = (st[o*2+1].r - st[o*2+1].l + 1) * st[o*2+1].set;
	}
	if(st[o].add != 0){
		if(st[o*2+1].set != -1) pushdown(o*2+1);
		if(st[o*2].set != -1) pushdown(o*2);
		st[o*2].val += (st[o*2].r - st[o*2].l + 1) * st[o].add;
		st[o*2+1].val += (st[o*2+1].r - st[o*2+1].l + 1) * st[o].add;
		st[o*2].add += st[o].add;
		st[o*2+1].add += st[o].add;
		st[o].add = 0;
	}
}

void build(int l,int r,int o){
	st[o].l = l , st[o].r = r , st[o].add = 0 , st[o].set = -1;
	if(l == r) {
		st[o].val = a[l]; return;
	}
	int mid = (l + r) / 2;
	if(l <= mid) build(l,mid,o*2);
	if(r > mid) build(mid+1,r,o*2+1);
	pushup(o);
}

void Add(int l,int r,int v,int o){
	if(st[o].l == l && st[o].r == r){
		if(st[o].set != -1) pushdown(o);
		st[o].val += v * (st[o].r - st[o].l + 1);
		st[o].add += v;
		return;
	}
	if(st[o].set != -1) pushdown(o);
	pushdown(o);
	int mid = (st[o].l + st[o].r) / 2;
	if(l > mid) Add(l,r,v,o*2+1);
	else if(r <= mid) Add(l,r,v,o*2);
	else {
		Add(l,mid,v,o*2);
		Add(mid+1,r,v,o*2+1);
	}
	pushup(o);
}

void Set(int l,int r,int v,int o) {
	if(st[o].l == l && st[o].r == r){
		st[o].val = v * (st[o].r - st[o].l + 1);
		st[o].set = v; st[o].add = 0;
		return;
	}
	pushdown(o);
	int mid = (st[o].l + st[o].r) / 2;
	if(l > mid) Set(l,r,v,o*2+1);
	else if(r <= mid) Set(l,r,v,o*2);
	else {
		Set(l,mid,v,o*2);
		Set(mid+1,r,v,o*2+1);
	}
	pushup(o);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i = 1; i <= n+1; i++)
		scanf("%d",&a[i]);
	build(1,n+1,1);
	for(int i = 0; i < m; i++){
		int op,l,r,val;
		scanf("%d%d%d%d",&op,&l,&r,&val);
		if(!op) Add(l+1,r+1,val,1);
		else Set(l+1,r+1,val,1);
		printf("%d\n",st[1].val);
	}
	return 0;
}

