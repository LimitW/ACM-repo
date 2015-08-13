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
const int mod = 258280327;
const int maxn = 2e5 + 3;
//const int maxm = maxn * maxn;

int dp[maxn][11];
int a[maxn];

int add(int a, int b){
	return (a + b) % 9 ? (a + b) % 9 : 9;
}

int main(){
    int T; scanf("%d", &T);
     while(T--){
         int n, x, y; scanf("%d %d %d", &n, &x, &y);
         for(int i = 1; i <= n; ++i)
             for(int j = 0; j < 10; ++j)
            	 dp[i][j] = 0;
         int cnt = 0;
         for(int i = 1; i <= n; ++i){
             scanf("%d", &a[i]);
             cnt = add(cnt,a[i]);
         }
         dp[1][0] = 1;
         dp[1][add(a[1],0)] = 1;
         for(int i = 2; i <= n; ++i){
             for(int j = 0; j < 10; ++j){
                 dp[i][j] = dp[i-1][j];
             }
         	 for(int j = 0; j < 10; ++j){
         		 int nxtj = add(j,a[i]);
                 dp[i][nxtj] += dp[i-1][j];
                 dp[i][nxtj] %= mod;
         	 }
         }
         int ans = 0;
         if(add(x,y) == cnt){
        	 ans += dp[n][x];
        	 if(x == cnt) --ans;
         }
         if(x == cnt) ++ans;
         if(y == cnt) ++ans;
         printf("%d\n", ans % mod);
    }
    return 0;
}

