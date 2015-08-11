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

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 3;
//const int maxm = maxn * maxn;

int n,q;

map<int,int> mp;
int u[2*maxn];

struct que{
	int x,y;
	char c;
}que[maxn];

vector<int> v;

struct node{
	int l,r,v,lazy;
};

struct segment{

	node st[8*maxn];

	void pushdown(int o){
		if(st[o].lazy){
			st[o<<1].lazy = max(st[o].lazy,st[o<<1].lazy);
			st[o<<1].v = max(st[o<<1].v,st[o].lazy);
			st[o<<1|1].lazy = max(st[o<<1|1].lazy,st[o].lazy);
			st[o<<1|1].v = max(st[o<<1|1].v,st[o].lazy);
			st[o].lazy = 0;
		}
	}

	void pushup(int o){
		st[o].v = max(st[o<<1|1].v,st[o<<1].v);
	}

	void build(int o,int l,int r){
		st[o].l = l; st[o].r = r; st[o].v = 1; st[o].lazy = 0;
		if(l == r) return;
		int mid = (l + r) >> 1;
		if(l <= mid) build(o<<1,l,mid);
		if(mid < r) build(o<<1|1,mid+1,r);
		pushup(o);
	}

	void update(int o,int l,int r,int v){
		if(l > r) return;
		if(st[o].l >= l && st[o].r <= r){
			st[o].lazy = max(st[o].lazy,v);
			st[o].v = max(st[o].v,v);
			return;
		}
		pushdown(o);
		int mid = (st[o].l + st[o].r) >> 1;
		if(r <= mid) update(o<<1,l,r,v);
		else if(l > mid) update(o<<1|1,l,r,v);
		else{
			update(o<<1,l,mid,v);
			update(o<<1|1,mid+1,r,v);
		}
		pushup(o);
	}

	int query(int o,int p){
		if(st[o].l == p && st[o].r == p)
			return st[o].v;
		pushdown(o);
		int mid = (st[o].l + st[o].r) >> 1;
		if(p <= mid) return query(o<<1,p);
		else return query(o<<1|1,p);
	}
}t[2];

int main(){
	scanf("%d%d",&n,&q);
	v.clear();
	v.push_back(0);
	v.push_back(n+1);
	for(int i = 0; i < q; ++i){
		scanf("%d %d %c",&que[i].x,&que[i].y,&que[i].c);
		v.push_back(que[i].x);
		v.push_back(que[i].y);
	}
	sort(v.begin(), v.end());
//	int sz = v.size();
	//for(int i = 1; i < sz; ++i){
	//	if(v[i] - v[i-1] > 1)
	//		v.push_back(v[i-1]+1);
//	}
	//sort(v.begin(), v.end());
	int sz = unique(v.begin(), v.end()) - v.begin();
	for(int i = 0; i < sz; ++i){
		mp[v[i]] = i + 1;
		u[i+1] = v[i];
	}
	t[0].build(1,1,sz);
	t[1].build(1,1,sz);
	set<int> vis;
	vis.clear();
	for(int i = 0; i < q; ++i){
		if(vis.find(que[i].x) != vis.end()){
			printf("0\n");
			continue;
		}
		vis.insert(que[i].x);
		int a = mp[que[i].x], b = mp[que[i].y];
		if(que[i].c == 'L'){
			int v = t[0].query(1,b);
			printf("%d\n",max(u[a]-u[v],0));
			t[1].update(1,v+1,a,b);
		}
		else {
			int v = t[1].query(1,a);
			printf("%d\n",max(u[b]-u[v],0));
			t[0].update(1,v+1,b,a);
		}
	}
    return 0;
}

