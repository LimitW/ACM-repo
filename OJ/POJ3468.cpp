//============================================================================
// Name        : POJ3468.cpp
// Author      : LimitW
// Date        : 2014.11.13
// Version     :
// Copyright   : POJ 3468
// Description : Segment Tree (Interval update)
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
const int maxn = 100000 + 5;

int n,m;
LL sumv[maxn*4],addv[maxn*4];

void pushup(int o){
    sumv[o] = sumv[o*2] + sumv[o*2+1];
}

void pushdown(int o,int L,int R){
    int len = R - L + 1;
    if(addv[o] != 0){
        addv[o*2] += addv[o];
        addv[o*2+1] += addv[o];
        sumv[o*2] += addv[o] * (len - len / 2);
        sumv[o*2+1] += addv[o] * (len / 2);
        addv[o] = 0;
    }
    return;
}

void build(int o,int L,int R)
{
    addv[o] = 0;
    if(L == R){
        scanf("%lld",&sumv[o]);
        return;
    }
    int M = (L + R) / 2;
    if(1 <= M) build(o*2,L,M);
    if(n > M) build(o*2+1,M+1,R);
    pushup(o);
}

void Add(int o,int L,int R,int y1,int y2,int v){
    if(y1 <= L && y2 >= R){
        addv[o] += (LL) v;
        sumv[o] += (LL) (v*(R-L+1));
    }
    else{
        pushdown(o,L,R);
        int M = (L + R) / 2;
        if(y1 <= M) Add(o*2,L,M,y1,y2,v);
        if(y2 > M) Add(o*2+1,M+1,R,y1,y2,v);
        pushup(o);
    }
    return;
}

LL query(int o,int L,int R,int y1,int y2){
    if(y1 <= L && y2 >= R){
        return sumv[o];
    }
    LL ans = 0;
    pushdown(o,L,R);
    int M = (L + R) / 2;
    if(y1 <= M) ans += query(o*2,L,M,y1,y2);
    if(y2 > M) ans += query(o*2+1,M+1,R,y1,y2);
    pushup(o);
    return ans;
}

int main(){
    while(~scanf("%d%d",&n,&m))
    {
        build(1,1,n);
        for(int i = 0 ; i < m; i++)
        {
            char op; int l,r,v;
            cin >> op;
            if(op == 'C')
            {
                scanf("%d%d%d",&l,&r,&v);
                Add(1,1,n,l,r,v);
            }
            if(op == 'Q')
            {
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(1,1,n,l,r));
            }
        }
    }
    return 0;
}