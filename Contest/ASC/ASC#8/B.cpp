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

const int maxn = 3e4 + 3;

int r , n , m;

struct mat {
	int a11,a12,a21,a22;
	mat(int a = 1,int b = 0,int c = 0,int d = 1){
		a11 = a; a12 = b; a21 = c; a22 = d;
	}
	mat operator * (mat b) const{
		mat c;
		c.a11 = (a11*b.a11 + a12*b.a21)%r;
		c.a12 = (a11*b.a12 + a12*b.a22)%r;
		c.a21 = (a21*b.a11 + a22*b.a21)%r;
		c.a22 = (a21*b.a12 + a22*b.a22)%r;
		return c;
	}
}a[maxn];

struct node {
	int l , r;
	mat val;
}st[maxn*4];

void pushup(int o){
	st[o].val = st[o*2].val * st[o*2+1].val;
}

void build(int l,int r,int o){
	st[o].l = l , st[o].r = r;
	if(l == r) {
		st[o].val = a[l]; return;
	}
	int mid = (l + r) / 2;
	if(l <= mid) build(l,mid,o*2);
	if(r > mid) build(mid+1,r,o*2+1);
	pushup(o);
}

mat query(int l,int r,int o){
	if(st[o].l == l && st[o].r == r){
		return st[o].val;
	}
	int mid = (st[o].l + st[o].r) / 2;
	if(l > mid) return query(l,r,o*2+1);
	else if(r <= mid) return query(l,r,o*2);
	else return query(l,mid,o*2) * query(mid+1,r,o*2+1);
}

int main(){
	int T = 1;
	while(~scanf("%d%d%d",&r,&n,&m)){
		if(T != 1) puts(""); ++T;
  		for(int i = 1; i <= n; i++){
			int a1,a2,a3,a4;
			scanf("%d%d",&a1,&a2);
			scanf("%d%d",&a3,&a4);
			mat c(a1,a2,a3,a4); a[i] = c;
		}
		build(1,n,1);
		for(int i = 0; i < m; i++){
			int l,r; scanf("%d%d",&l,&r);
			mat c = query(l,r,1);
			printf("%d %d\n%d %d\n",c.a11,c.a12,c.a21,c.a22);
			if(i != m-1) puts("");
		}
	}
	return 0;
}

