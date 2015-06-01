//============================================================================
// Name        : C.cpp
// Author      : LimitW
// Date        : 2014.11.6
// Version     :
// Copyright   : Codeforces #276 Div2 C
// Description : bit
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

int getval(LL n)
{
    int ans = 0;
    while(n){
        ans++; n /= 2;
    }
    return ans;
}

int getval2(LL n){
    int ans = 0;
    while(n){
        if(n & 1) ans++; n >>= 1;
    }
    return ans;
}

LL pow2(int n){
    LL ans = 1;
    for(int i = 0; i < n; i++)
        ans *= 2;
    return ans;
}

int main(){
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++){
        LL l , r;
        scanf("%I64d%I64d",&l,&r);
        if(r == l) { printf("%I64d\n",l); continue; }
        int y = getval(r) , x = getval(l);
        LL ans = r;
        if(x != y){
            ans = (getval2(pow2(y-1) -1) >= getval2(ans)) ? pow2(y-1)-1 : ans;
            printf("%I64d\n",ans); continue;
        }
        ans = l;
        for(int j = 0; j < x; j++){
            if( (l & (1ll << j)) == 0)
                l += (1ll << j);
            if(l > r){
                l -= (1ll << j); break;
            }
        }
        ans = getval2(ans) >= getval2(l) ? ans : l;
        printf("%I64d\n",ans);
    }
    return 0;
}