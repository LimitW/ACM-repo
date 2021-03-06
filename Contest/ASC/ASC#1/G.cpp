//============================================================================
// Name        : G.cpp
// Author      : LimitW
// Date        : 2014.10.29
// Version     :
// Copyright   : ASC #1 G
// Description : LIS nlogn
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

const int maxn = 1e5 + 10;

struct node
{
    int s,b;
    int id;
}p[maxn];

int dp[maxn];
int path[maxn];

bool cmp(node x, node y)
{
    if(x.s != y.s) return x.s < y.s;
    return x.b > y.b;
}

void output(int i){
    if(path[i] == -1){
        printf("%d\n",p[i].id);
    }
    else{
    printf("%d ",p[i].id);
    output(path[i]);
    }
}

int main(){
    memset(dp,0,sizeof(dp));
    memset(path,0,sizeof(path));
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&p[i].s,&p[i].b);
        p[i].id = i + 1;
    }
    sort(p,p+n,cmp);
    int k = 0;
    dp[0] = 0;
    path[0] = -1;
    for(int i = 1; i < n; i++)
    {
        if( p[i].b > p[dp[k]].b)
        { path[i] = dp[k] ; dp[++k] = i; }
        else{
            int l = 0 , r = k + 1;
            while( l < r )
            {
                int m = ( l + r ) / 2;
                if(p[i].b > p[dp[m]].b) l = m + 1;
                else r = m;
            }
            dp[r] = i; path[i] = (r == 0) ? -1 : dp[r-1];
        }
    }
    printf("%d\n",k+1);
    output(dp[k]);
    return 0;
}
