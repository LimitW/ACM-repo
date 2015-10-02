//============================================================================
// Name        : H.cpp
// Author      : LimitW
// Date        : 2014.11.16
// Version     :
// Copyright   : 2014 Beijing Onsite H
// Description : dp / bag problem
//               Never forgot your awful '1ll' in Beijing.
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
const int maxm = (1<<20) - 1;

LL dp[42][maxm+10];
int a[42];

int main(){
        int T; scanf("%d",&T);
        for(int kase = 1; kase <= T; kase++){
            int n,m; scanf("%d%d",&n,&m);
            for(int i = 1; i <= n; i++)
                scanf("%d",&a[i]);
            dp[0][0] = 1;
            for(int i = 1; i <= n; i++)
                for(int j = 0; j < maxm; j++){
                    dp[i][j] = dp[i-1][j^a[i]] + dp[i-1][j];
                }
            LL ans = 1ll << n;
            for(int i = 0; i < m; i++)
                ans -= dp[n][i];
            printf("Case #%d: %lld\n",kase,ans);
        }
        return 0;
}
