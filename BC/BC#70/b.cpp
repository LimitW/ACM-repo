#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int a[21], n;
bool dp[21][2100];

int main(){
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase){
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", a + i);
        }
        dp[0][0] = true;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 2100; ++j){
                if(dp[i][j]){
                    if(j + a[i] < 2100)
                        dp[i + 1][j + a[i]] = 1;
                    if(j - a[i] >= 0)
                        dp[i + 1][j - a[i]] = 1;
                    dp[i + 1][j] = 1;
                }
            }
        int m; scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            int v; scanf("%d", &v);
            if(v >= 2100) puts("NO");
            else puts(dp[n][v] ? "YES" : "NO");
        }
    }
    return 0;
}