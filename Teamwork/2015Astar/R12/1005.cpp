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

const int maxn = 1e5+10;

int a[maxn] ,  b[maxn];

int bsearch(int v,int l,int r){
	int mid;
	while(l <= r){
		mid = (l + r) / 2;
		if(v >= b[mid]) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int LIS(int n){
	b[1] = a[1];
	int len = 1;
	for(int i = 2; i <= n; ++i){
		if(a[i] >= b[len]) b[++len] = a[i];
		else b[bsearch(a[i],1,len)] = a[i];
	}
	return len;
}

int main(){
    int T; scanf("%d",&T);
    for(int kase = 1; kase <= T; ++kase){
        printf("Case #%d:\n",kase);
        memset(b,0,sizeof(b));
        int n; scanf("%d",&n);
        for(int i = 1; i <= n; ++i){
            scanf("%d",&a[i]);
            a[i] -= i;
        }
        printf("%d\n" , n - LIS(n));
    }
    return 0;
}

