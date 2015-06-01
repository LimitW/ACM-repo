/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.10.4
 * Source:LA 4329 Beijing 2008
 * Note:BIT
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

#define ll long long

const int INF = 0x3f3f3f3f;
const int maxn = 2e4 + 10;
const int SIZE = 1e5 + 10;

ll a[maxn],c[maxn],d[maxn];
ll t[SIZE];

int lowbit(int x)
{
	return x & -x;
}

ll sum(ll x)
{
	ll ret = 0;
	while(x > 0){
		ret += t[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(ll x)
{
	while(x <= SIZE){
		t[x]++;
		x += lowbit(x);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(t,0,sizeof(t));
		for(int i = 0; i < n; i++)
			scanf("%lld",&a[i]);
		for(int i = 0; i < n; i++)
		{
			add(a[i]);
			c[i] = sum(a[i]-1);
		}
		memset(t,0,sizeof(t));
		for(int i = n - 1; i >= 0; i--)
		{
			add(a[i]);
			d[i] = sum(a[i]-1);
		}
		long long sum = 0;
		for(int i = 1; i <= n; i++)
			sum += c[i-1]*(n-i-d[i-1]) + d[i-1]*(i-1-c[i-1]);
		printf("%lld\n",sum);
	}
	return 0;
}