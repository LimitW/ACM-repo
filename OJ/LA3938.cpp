/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.10.5
 * Source:LA 3938
 * Note:Segment Tree 点修改
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
#include <utility>
#include <functional>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 5e5 + 10;
const int maxnode = 1000000 + 10;

typedef long long LL;
typedef pair<int,int> interval;

LL prefix_sum[maxn];

LL sum(int l,int r)
{
	return prefix_sum[r] - prefix_sum[l-1];
}

LL sum(interval p)
{
	return sum(p.first,p.second);
}

interval better(interval a,interval b){
	if(sum(a) != sum(b)) return sum(a) > sum(b) ? a : b;
	return a < b ? a : b;
}

int ql,qr;

struct intervalTree
{
	int max_prefix[maxnode];
	int max_suffix[maxnode];
	interval max_sub[maxnode];

	void build(int o,int l, int r)
	{
		if(l == r){
			max_prefix[o] = max_suffix[o] = l;
			max_sub[o] = make_pair(l,l);
		}
		else{
			int m = l + (r - l) / 2;

			int lc = o*2, rc = o*2+1;
			build(lc,l,m);
			build(rc,m+1,r);

			LL v1 = sum(l,max_prefix[lc]);
			LL v2 = sum(l,max_prefix[rc]);
			if(v1 == v2) max_prefix[o] = min(max_prefix[lc],max_prefix[rc]);
			else max_prefix[o] = v1 > v2 ? max_prefix[lc] : max_prefix[rc];

			v1 = sum(max_suffix[lc],r);
			v2 = sum(max_suffix[rc],r);
			if(v1 == v2) max_suffix[o] = min(max_suffix[lc],max_suffix[rc]);
			else max_suffix[o] = v1 > v2 ? max_suffix[lc] : max_suffix[rc];
			
			max_sub[o] = better(max_sub[lc],max_sub[rc]);
			max_sub[o] = better(max_sub[o],make_pair(max_suffix[lc],max_prefix[rc]));
		}
	}

	interval query_prefix(int o,int l,int r)
	{
		if(max_prefix[o] <= qr) return make_pair(l,max_prefix[o]);
		int m = l + (r-l)/2;
		int lc = o*2,rc = o*2+1;
		if(qr <= m) return query_prefix(lc,l,m);
		interval i = query_prefix(rc,m+1,r);
		i.first = l;
		return better(i,make_pair(l,max_prefix[lc]));
	}

	interval query_suffix(int o,int l,int r)
	{
		if(max_suffix[o] >= ql) return make_pair(max_suffix[o],r);
		int m = l + (r-l)/2;
		int lc = o*2, rc = o*2+1;
		if(ql > m) return query_suffix(rc,m+1,r);
		interval i = query_suffix(lc,l,m);
		i.second = r;
		return better(i,make_pair(max_suffix[rc],r));
	}

	interval query(int o,int l,int r)
	{
		if(ql <= l && r <= qr) return max_sub[o];
		int m = l + (r-l)/2;
		int lc = o*2 , rc = o*2+1;
		if(qr <= m) return query(lc,l,m);
		if(ql > m) return query(rc,m+1,r);
		interval i1 = query_prefix(rc,m+1,r);
		interval i2 = query_suffix(lc,l,m);
		interval i3 = better(query(lc,l,m),query(rc,m+1,r));
		return better(make_pair(i2.first,i1.second),i3);
	}
};

intervalTree tree;

int main(){
	int n,m;
	int a;
	int caseno = 0;
	while(scanf("%d",&n) != EOF){
		scanf("%d",&m);
		prefix_sum[0] = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a);
			prefix_sum[i+1] = prefix_sum[i] + a;
		}
		tree.build(1,1,n);
		printf("Case %d:\n",++caseno);
		for(int i = 0; i < m; i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			ql = l ; qr = r;
			interval ans = tree.query(1,1,n);
			printf("%d %d\n",ans.first,ans.second);
		}
	}
	return 0;
}