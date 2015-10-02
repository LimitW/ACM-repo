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

const int maxn = 200 +5;

int atk[maxn] , add[maxn];
int dp[maxn][maxn];

int main(){
    int T; scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        int n; scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        atk[0] = atk[n+1] = 0; add[0] = add[n+1] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d",&atk[i]);
            dp[i][i] = atk[i];
        }
        for(int i = 1; i <= n; i++)
            scanf("%d",&add[i]);
        for(int l = 2; l <= n; l++)
        {
            for(int i = 1; i + l - 1 <= n; i++){
            	dp[i][i+l-1] = INF;
                for(int j = i ; j <= i + l - 1; j++)
                {
                	int pre = dp[i][j-1], mid = atk[j] , nxt = dp[j+1][i+l-1];
                	if(i <= j - 1) { pre += add[j] + add[i-1]; }
                	if(j + 1 <= i + l - 1) { nxt += add[j] + add[i+l]; }
                    dp[i][i+l-1] = min(pre + mid + nxt , dp[i][i+l-1]);
                }
             //   printf("left = %d , right = %d , val = %d\n",i,i+l-1,dp[i][i+l-1]);
            }
        }
        printf("Case #%d: %d\n",kase,dp[1][n]);
    }
    return 0;
}
