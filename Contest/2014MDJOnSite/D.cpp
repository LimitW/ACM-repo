//============================================================================
// Name        : D.cpp
// Author      : LimitW
// Date        : 2014.10.30
// Version     :
// Copyright   : 2014 Mudangjiang Onsite D
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

double dp[52][52][2500+10];

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1.0;
        int ma = n * m;
        for(int k = 1; k <= ma; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                {
                    dp[i][j][k] += ( dp[i-1][j][k-1] * (n - i + 1) * j ) * 1.0 / ( ma - k + 1 );
                    dp[i][j][k] += ( dp[i][j-1][k-1] * (m - j + 1) * i ) * 1.0 / ( ma - k + 1 );
                    dp[i][j][k] += ( dp[i-1][j-1][k-1] * (n  - i + 1) * ( m - j + 1) ) * 1.0 / ( ma - k + 1 );
                    dp[i][j][k] += ( dp[i][j][k-1] * (i * j - k + 1) ) * 1.0 / ( ma - k + 1 );
                }
        double ans = 0.0;
        for(int i = 1; i <= ma; i++) ans += (dp[n][m][k] - dp[n][m][k-1]) * i;
        printf("%.8lf\n",ans);
    }
    return 0;
}
