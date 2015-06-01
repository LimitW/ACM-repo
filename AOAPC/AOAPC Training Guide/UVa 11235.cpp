/************************************************
 * Title:Frequent Values
 * Author:LimitW
 * Date:2014.10.4
 * Source:UVa 11235
 * Note:RMQ
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

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;

int a[maxn];
int h[2*maxn];
int d[2*maxn][20];

struct item{
	int lpos,rpos;
};

map<int,item> posv;

void RMQ_init(int *a)
{
	for(int i = 0; i < 2*maxn; i++)
		d[i][0] = a[i];
	for(int j = 1; (1 << j) <= 2*maxn; j++)
		for(int i = 0; i + (1<<j) - 1 < 2*maxn; i++)
			d[i][j] = max( d[i][j-1] , d[i + (1<<(j-1))][j-1]);
}

int RMQ(int L,int R){
	int k = 0;
	while( (1<<(k+1)) <= R-L+1) k++;
	return max( d[L][k] , d[R-(1<<k)+1][k] );
}

int main(){
	int n,q;
	while(scanf("%d",&n) && n != 0)
	{
		scanf("%d",&q);
		memset(h,0,sizeof(h));
		memset(d,0,sizeof(d));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
			a[i] += 100000;
			h[a[i]]++;
		}
		for(int i = 1; i <= n; i += h[a[i]])
		{
			item t;
			t.lpos = i;
			t.rpos = i + h[a[i]] - 1;
			posv[a[i]] = t;
		}
		RMQ_init(h);
		for(int i = 0; i < q; i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			int ans;
			if(a[l] == a[r])
                ans = RMQ(a[l],a[r]) - ((posv[a[r]].rpos - r) + (l - posv[a[l]].lpos));
            else
            {
                int ans1 = h[a[l]] - (l - posv[a[l]].lpos);
                int ans2 = h[a[r]] - (posv[a[r]].rpos - r);
                int kl = posv[a[l]].rpos + 1;
                int kr = posv[a[r]].lpos - 1;
                int ans3;
                if(kl > kr) ans3 = 0;
                else ans3 = RMQ(a[kl],a[kr]);
                ans = max(ans1,ans2);
                ans = max(ans,ans3);
            }
			printf("%d\n",ans);
		}
	}
	return 0;
}