//============================================================================
// Name        : AOAPC_10_1_2.cpp
// Author      : LimitW
// Date        : 2014.12.10
// Version     :
// Copyright   : AOAPC I
// Description : Sieve of Eratosthenes
//============================================================================

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
const int maxn = 1e7 + 3;
const int maxprime = 1e6 + 3;
bool prime[maxprime];
bool vis[maxn];

int main(){
    LL n,m; scanf("%lld%lld",&n,&m);
    memset(vis,0,sizeof(vis));
    int r = sqrt(m+0.5);
    for(int i = 2; i <= r; i++){
        if(prime[i]) continue;
        //prime2[c++] = i;
        for(LL j = i*i; j <= m; j += i) prime[j] = 1;
    }// prime-table
    for(int i = 2; i <= r; i++)
    {
        if(prime[i]) continue;
        for(LL j = i; j * j <= m; j += i)
            if(j * j >= n) vis[j * j - n] = 1;
    }// sieve of [n,m]
    int ans = 0;
    for(int i = 0; i <= m - n; i++){
        if(!vis[i]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
//999990000000 1000000000000