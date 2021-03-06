//============================================================================
// Name        : E.cpp
// Author      : LimitW
// Date        : 2014.11.1
// Version     :
// Copyright   : 2014 Anshan Onsite E
// Description : dp
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

const int INF = 0x3f3f3f3f;

int a[110] , f[52][52] , dp[102][52];

int main(){
    int T; scanf("%d",&T);
    while(T--)
    {
        int n,m; scanf("%d%d",&n,&m);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&f[i][j]);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        if(a[0] == -1){
            for(int i = 0; i < m; i++)
                dp[0][i] = 0;
        }
        else dp[0][a[0]-1] = 0;
        for(int i = 1; i < n; i++)
        {
                if(a[i] == -1){
                    for(int j = 0; j < m; j++){
                        for(int k = 0; k < m; k++){
                            if(dp[i-1][j] == -1) continue;
                            dp[i][k] = max(dp[i][k],dp[i-1][j]+f[j][k]);
                        }
                    }
                }
                if(a[i] > 0){
                    for(int j = 0; j < m; j++){
                        if(dp[i - 1][j] == -1) continue;
                        dp[i][a[i]-1] = max(dp[i][a[i]-1],dp[i-1][j]+f[j][a[i]-1]);
                    }
                }
            }
        int ans = 0;
        for(int i = 0; i < m; i++)
            ans = max(ans,dp[n-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
