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

const int maxn = 1e6 + 3;

int a[maxn] , n , m;

struct node {
	int l , r , val;
}st[maxn*4];

void pushup(int o){
	st[o].val = min(st[o*2].val , st[o*2+1].val);
}

void build(int l,int r,int o){
	st[o].l = l , st[o].r = r;
	if(l == r) {
		st[o].val = a[l]; return;
	}
	int mid = (l + r) / 2;
	if(l <= mid)build(l,mid,o*2);
	if(r >= mid + 1) build(mid+1,r,o*2+1);
	pushup(o);
}

void update(int p,int v,int o) {
	if(st[o].l == p && st[o].r == p){
		st[o].val = v; return;
	}
	int mid = (st[o].l + st[o].r) / 2;
	if(p <= mid) update(p,v,o*2);
	else update(p,v,o*2+1);
	pushup(o);
}

int query(int l,int r,int o){
	if(st[o].l == l && st[o].r == r){
		return st[o].val;
	}
	int mid = (st[o].l + st[o].r) / 2;
	if(l > mid) return query(l,r,o*2+1);
	else if(r <= mid) return query(l,r,o*2);
	else return min(query(l,mid,o*2),query(mid+1,r,o*2+1));
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	build(1,n,1);
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		int op,l,r,val;
		scanf("%d",&op);
		if(!op){
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r,1));
		}
		else{
			scanf("%d%d",&l,&val);
			update(l,val,1);
		}
	}
	return 0;
}

