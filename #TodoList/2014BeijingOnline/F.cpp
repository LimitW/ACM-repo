//============================================================================
// Name        : F.cpp
// Author      : LimitW
// Date        : 2014.10.31
// Version     :
// Copyright   : 2014 Beijing Online F
// Description : Greedy
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

const int maxn = 2e5+10;

int st[maxn];
int main(){
    int T;
    scanf("%d",&T);
    for(int CaseNo = 1; CaseNo <= T; CaseNo++){
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        st[0] = 0; st[n+1] = m;
        for(int i = 1; i <= n; i++)
            scanf("%d",&st[i]);
        sort(st,st+n+2);
        int ans = 0 , k = l;
        for(int i = 1; i <= n + 1; i++)
        {
            int x = (st[i] - st[i-1]) % (l + 1);
            int y = (st[i] - st[i-1]) / (l + 1);
            ans += 2*y;
            if(k + x >= l + 1)
            {
                k = x; ans++;
            }
            else  k += x;
        }
        printf("Case #%d: %d\n",CaseNo,ans);
    }
    return 0;
}