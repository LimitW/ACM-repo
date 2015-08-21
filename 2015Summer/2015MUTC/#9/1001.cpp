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
const int mod = 1e9 + 7;

LL y[203];
LL dp[103][103];
char s[103];

LL solve(int i,LL a,LL b,int n1 = 0,int n2 = 0){
    LL ans;
    if(s[i] == '+')
        ans = y[n2] * a + y[n1] * b;
    else if(s[i] == '-')
        ans = y[n2] * a - y[n1] * b;
    else {
        ans = a * b;
        ans %= mod;
    }
    return ans % mod;
}

LL c[103][103];

int main(){
    y[0] = y[1] = 1ll;
    for(int i = 2; i <= 200; ++i){
        y[i] = y[i-1] * i;
        y[i] %= mod;
    }
    c[0][0] = 1;
    for(int i = 1; i <= 100; ++i){
        c[i][0] = 1;
        for(int j = 1; j <= 100; ++j){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
            c[i][j] %= mod;
        }
    }
    int n;
    while(~scanf("%d", &n)){
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; ++i){
            scanf("%I64d", &dp[i][i]);
        }
        scanf("%s",s+1);
        for(int k = 1; k < n; ++k){
            for(int i = 1; i <= n; ++i){
                int j = i + k;
                if(i + k > n) break;
                for(int z = i; z < j; ++z){
                    LL aa = solve(z,dp[i][z],dp[z+1][j],z-i,j-z-1);
                    if(j - i > 1 && j - 1 >= z)
                        aa = aa * c[j-i-1][z-i];
                    dp[i][j] += aa;
                    dp[i][j] %= mod;
                }
            }
        }
        if(dp[1][n] < 0) dp[1][n] += mod;
        printf("%I64d\n",dp[1][n]);
    }
    return 0;
}
