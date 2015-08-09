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
const int maxn = 30 + 3;
const int maxm = 100 + 3;

LL dp[62][35];

int main(){
    for(int i = 0; i < 61; ++i) dp[i][0] = 1;
    dp[1][1] = 1, dp[2][1] = 2, dp[3][1] = 3;
    for(int i = 4; i < 61; ++i){
        int v = (i & 1) ? i / 2 + 1 : i / 2;
        for(int j = 1; j <= v; ++j){
            dp[i][j] = dp[i-3][j-1] + dp[i-1][j];
        }
    }
    int n;
    while(~scanf("%d",&n)){
        LL ans = 0;
        for(int i = 1; i < 32; ++i)
            ans += dp[n][i];
        cout << ans << '\n';
    }
    return 0;
}
