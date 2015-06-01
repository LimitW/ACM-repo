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

int a[maxn];

struct node {
	int l , r , val , lazy;
}st[maxn*4];

void pushup(int o){
	st[o].val = st[o*2].val + st[o*2+1].val;
}

void pushdown(int o){
	if(!st[o].lazy) return;
	st[o*2].lazy = st[o*2+1].lazy = st[o].lazy;
	st[o].lazy = 0;
	st[o*2].val = (st[o*2].r - st[o*2].l + 1) * st[o*2].lazy;
	st[o*2+1].val = (st[o*2+1].r - st[o*2+1].l + 1) * st[o*2+1].lazy;
}

void build(int l,int r,int o){
	st[o].l = l , st[o].r = r , st[o].lazy = 0;
	if(l == r) {
		st[o].val = a[l]; return;
	}
	int mid = (l + r) / 2;
	if(l <= mid) build(l,mid,o*2);
	if(r > mid) build(mid+1,r,o*2+1);
	pushup(o);
}

void update(int l,int r,int v,int o) {
	if(st[o].l == l && st[o].r == r){
		st[o].val = v * (st[o].r - st[o].l + 1); st[o].lazy = v; return;
	}
	pushdown(o);
	int mid = (st[o].l + st[o].r) / 2;
	if(l > mid) update(l,r,v,o*2+1);
	else if(r <= mid) update(l,r,v,o*2);
	else {
		update(l,mid,v,o*2);
		update(mid+1,r,v,o*2+1);
	}
	pushup(o);
}

int query(int l,int r,int o){
	if(st[o].l == l && st[o].r == r){
		return st[o].val;
	}
	pushdown(o);
	int mid = (st[o].l + st[o].r) / 2;
	if(l > mid) return query(l,r,o*2+1);
	else if(r <= mid) return query(l,r,o*2);
	else return query(l,mid,o*2) + query(mid+1,r,o*2+1);
}

int main(){
	int n; scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	build(1,n,1);
	int m; scanf("%d",&m);
	for(int i = 0; i < m; i++){
		int op,l,r,val;
		scanf("%d",&op);
		if(!op){
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r,1));
		}
		else{
			scanf("%d%d%d",&l,&r,&val);
			update(l,r,val,1);
		}
	}
	return 0;
}

