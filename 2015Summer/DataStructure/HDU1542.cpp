//Segment Tree Scanline
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
const int maxn = 110;
//const int maxm = maxn * maxn;

struct line{
	double x, y, h;
	int d;
	line(){}
	line(double xx, double yy, double hh, int dd): x(xx), y(yy), h(hh), d(dd){};
	bool operator < (line b) const{
		return h < b.h;
	}
}l[2*maxn];

double v[2*maxn], f[2*maxn];
map<double,int> u;

struct node{
	int l, r, d;
	double v;
};

struct segment{

	node st[8*maxn];

	void pushup(int o){
		if(st[o].d) st[o].v = f[st[o].r+1] - f[st[o].l];
		else if(st[o].r == st[o].l) st[o].v = 0;
		else st[o].v = st[o<<1].v + st[o<<1|1].v;
	}

	void build(int o,int l,int r){
		if(l > r) return;
		st[o].l = l, st[o].r = r, st[o].v = st[o].d = 0;
		if(l == r) return;
		int mid = l + r >> 1;
		build(o<<1,l,mid);
		build(o<<1|1,mid+1,r);
		pushup(o);
	}

	void update(int o,int l,int r,int v){
		if(st[o].l == l && st[o].r == r){
			st[o].d += v;
			pushup(o);
			return;
		}
		int mid = st[o].l + st[o].r >> 1;
		if(r <= mid) update(o<<1,l,r,v);
		else if(l > mid) update(o<<1|1,l,r,v);
		else{
			update(o<<1,l,mid,v);
			update(o<<1|1,mid+1,r,v);
		}
		pushup(o);
	}
}t;

int main(){
	int n, m, kase = 0;
	while(~scanf("%d", &n) && n){
		m = 0;
		for(int i = 0; i < n; ++i){
			double a, b, c, d;
			scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
			l[++m] = line(a,c,b,1);
			v[m] = a;
			l[++m] = line(a,c,d,-1);
			v[m] = c;
		}
		sort(v+1,v+m+1);
		sort(l+1,l+m+1);
		u.clear();
		for(int i = 1; i <= m; ++i){
			u[v[i]] = i;
			f[i] = v[i];
		}
		t.build(1,1,m);
		double ans = 0;
		for(int i = 1; i < m; ++i){
			// if l, r, f[r]-f[l]
			// sum[o] = f[r] - f[mid+1] + f[mid] - f[l], WA
			// if l, r-1, f[r+1]-f[l]
			// sum[o] = f[r-1+1] - f[mid+1] + f[mid+1] - f[l], AC
			int x = u[l[i].x], y = u[l[i].y] - 1;
			if(x <= y) t.update(1,x,y,l[i].d);
			ans += t.st[1].v * (l[i+1].h - l[i].h);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",++kase,ans);
	}
    return 0;
}

