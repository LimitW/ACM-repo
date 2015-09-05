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
const int maxn = 1e5 + 3;
const int maxm = 2e5 + 3;
const double eps = 1e-9;

int h[maxn];
int dp[maxn];

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &h[i]);
    memset(dp, INF, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < n; ++i)
        dp[i] = min(dp[i], min( min(h[i], h[i-1] + 1), dp[i-1] + 1));
    dp[n-1] = 1;
    for(int i = n - 2; i > 0; --i)
        dp[i] = min(dp[i], min( min(h[i], h[i+1] + 1), dp[i+1] + 1));
    int ans = 0;
    for(int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}

