/************************************************
 * Title :
 * Author : LimitW
 * Date : 2014.10.20
 * Source : BestCoder #14 C
 * Note : SegmentTree  matrix
*************************************************/
#include <iostream>
#include <iomanip>
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
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long

const int INF = 0x3f3f3f3f;

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 10;

int n,m;

struct matrix {
	int l , r;
	LL a[3][3];
	matrix operator * (const matrix & b) const {
			matrix c;
			c.a[1][1] = (a[1][1] * (b.a)[1][1] + a[1][2] * (b.a)[2][1]) % MOD;
			c.a[1][2] = (a[1][1] * (b.a)[1][2] + a[1][2] * (b.a)[2][2]) % MOD;
			c.a[2][1] = (a[2][1] * (b.a)[1][1] + a[2][2] * (b.a)[2][1]) % MOD;
			c.a[2][2] = (a[2][1] * (b.a)[1][2] + a[2][2] * (b.a)[2][2]) % MOD;
			return c;
	}
} st[4*maxn];

void pushup(matrix & c, matrix & b1, matrix & b2){
	memset(c.a,0,sizeof(c.a));
	c.a[1][1] = (b1.a[1][1] * (b2.a)[1][1] + b1.a[1][2] * (b2.a)[2][1]) % MOD;
	c.a[1][2] = (b1.a[1][1] * (b2.a)[1][2] + b1.a[1][2] * (b2.a)[2][2]) % MOD;
	c.a[2][1] = (b1.a[2][1] * (b2.a)[1][1] + b1.a[2][2] * (b2.a)[2][1]) % MOD;
	c.a[2][2] = (b1.a[2][1] * (b2.a)[1][2] + b1.a[2][2] * (b2.a)[2][2]) % MOD;
}

void build(int L, int R, int p)
{
	st[p].l = L; st[p].r = R;
	if(L == R){
		st[p].a[1][1] = st[p].a[1][2] = st[p].a[2][1] = st[p].a[2][2] = 1;
		return;
	}
	int mid = (L + R) >> 1;
	build(L,mid,2*p);
	build(mid+1,R,2*p+1);
	pushup(st[p],st[2*p],st[2*p+1]);
}

void update(int x, int y, int z, int p)
{
	if(st[p].l == st[p].r)
	{
		st[p].a[y][z] ^= 1; return;
	}
	int mid = (st[p].l + st[p].r) >> 1;
	if(x <= mid) update(x,y,z,2*p);
	else update(x,y,z,2*p+1);
	pushup(st[p],st[2*p],st[2*p+1]);
}

matrix query(int L,int R,int p)
{
	if(st[p].l == L && st[p].r == R) return st[p];
	int mid = (st[p].l + st[p].r) >> 1;
	if(R <= mid) return query(L,R,2*p);
	else if(L > mid) return query(L,R,2*p+1);
	else{
		matrix t1 = query(L,mid,2*p);
		matrix t2 = query(mid+1,R,2*p+1);
		matrix ans;
		pushup(ans,t1,t2);
		return ans;
	}
};

int main(){
	while(~scanf("%d%d",&n,&m)) {
		build(1,n-1,1);
		for(int i = 0; i < m; i++)
		{
			int op,x,y,z;
			scanf("%d",&op);
			if(!op){
				scanf("%d%d",&x,&y);
				matrix ANS = query(x,y-1,1);
				LL ans = ( 0LL + ANS.a[1][1] + ANS.a[1][2] + ANS.a[2][1] + ANS.a[2][2] ) % MOD;
				printf("%lld\n",ans);
			}
			else{
				scanf("%d%d%d",&x,&y,&z);
				update(x,y,z,1);
			}
		}
	}
	return 0;
}
