//============================================================================
// Name        : D.cpp
// Author      : LimitW
// Date        : 2014.11.6
// Version     :
// Copyright   : Codeforces #274 Div2 D
// Description :
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
const int maxv = 1e6 + 5;
const int maxn = 2e5 + 5;
int pre[maxv],a[maxn];

int main(){
    memset(pre,-1,sizeof(pre));
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        pre[a[i]] = a[i];
    }
    for(int i = 1; i < maxv; i++)
        if(pre[i] == -1) pre[i] = pre[i-1];
    sort(a,a+n);
    n = unique(a,a+n) - a;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 2*a[i]; j < maxv; j += a[i])
            ans = max(ans , pre[j-1] % a[i]);
        ans = max(ans,pre[maxv - 1] % a[i]);
    }
    printf("%d\n",ans);
    return 0;
}

