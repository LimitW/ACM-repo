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
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const int maxn = 50010;

int n;
LL t[maxn];

LL lowbit(int x){
	return x & -x;
}

LL sum(int x)
{
	int ret = 0;
	while(x > 0){
		ret += t[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(LL x)
{
	while(x <= n){
		t[x]++;
		x += lowbit(x);
	}
}

LL a[maxn] , c1[maxn] , c2[maxn];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		memset(t,0,sizeof(t));
		scanf("%d",&n);
		memset(t,0,sizeof(t));
		for(int i = 1; i <= n; i++){
			scanf("%I64d",&a[i]);
		}
		c2[n+1] = 0;
		for(int i = n; i > 0; i--){
			c2[i] = c2[i+1] + sum(n) - sum(a[i]);
			add(a[i]);
		}
		memset(t,0,sizeof(t));
		for(int i = 1; i <= n; i++){
			add(a[i]);
			c1[i] = sum(a[i]-1);
		}
		LL ans = 0;
		for(int i = 2; i <= n - 2; i++){
			ans += c1[i] * c2[i+1];
		}
		printf("%I64d\n",ans);
	}
    return 0;
}
