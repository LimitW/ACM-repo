//============================================================================
// Name        : D.cpp
// Author      : LimitW
// Date        : 2014.10.18
// Version     :
// Copyright   : CF 274 D
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
const LL MOD = 1e9 + 7;
LL dp[200000 + 10];

int main(){
    LL r,g,h;
    cin >> r >> g;
    for(h = 1; h * (h + 1) / 2  <= ( r + g ); h++);
    h--;
    dp[0] = 1;
    for(int i = 1; i <= h; i++)
        for(int j = r; j >= i; j--)
        {
                dp[j] += dp[j-i];
                if(dp[j] >= MOD) dp[j] -= MOD;
        }
    LL ans = 0;
    for(int i = 0; i <= r; i++){
        if(i + g >= h * (h + 1) / 2) ans += dp[i];
        if(ans >= MOD) ans -= MOD;
    }
    printf("%I64d",ans);
    return 0;
}
