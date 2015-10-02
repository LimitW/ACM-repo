//============================================================================
// Name        : HDU4893.cpp
// Author      : LimitW
// Date        : 2014.11.12
// Version     :
// Copyright   : 2014 MUTC #3 G
// Description : Segment Tree
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
LL FB[100];
LL sumv[maxn*4] , fbsumv[maxn*4];
bool lazy[maxn*4];

void pushup(int o){
    int lc = o*2 , rc = o*2+1;
    sumv[o] = sumv[lc] + sumv[rc];
    fbsumv[o] = fbsumv[lc] + fbsumv[rc];
    return;
}

void pushdown(int o){
    if(lazy[o]){
        int lc = o*2 , rc = o*2+1;
        sumv[lc] = fbsumv[lc];
        sumv[rc] = fbsumv[rc];
        lazy[lc] = lazy[rc] = lazy[o];
        lazy[o] = false;
    }
    return;
}

void Build(int o,int L,int R)
{
    lazy[o] = false;
    if(L == R) { sumv[o] = 0; fbsumv[o] = 1; return; }
    int lc = o*2 , rc = o*2+1;
    int M = (L + R) / 2;
    Build(lc,L,M);
    Build(rc,M+1,R);
    pushup(o);
    return;
}

LL FbVal(LL x){
    LL ans = 1;
    if(x >= FB[92]) ans = FB[92];
    else if(x <= 1) ans = 1;
    else{
        int pos = upper_bound(FB,FB+93,x) - FB;
        if(pos > 0){
            if(FB[pos] - x  >= x - FB[pos-1])  ans = FB[pos-1];
            else ans = FB[pos];
        }
    }
    return ans;
}

void Add(int o,int L,int R,int k,int v){
    int lc = o*2 , rc = o*2+1;
    if(L == R){
        sumv[o] += (LL) v;
        fbsumv[o] = FbVal(sumv[o]);
    }
    else{
        pushdown(o);
        int M = (R + L) / 2;
        if(k <= M) Add(lc,L,M,k,v);
        else Add(rc,M+1,R,k,v);
        pushup(o);
    }
    return;
}

void Set(int o,int L,int R,int y1,int y2){
    int lc = o*2 , rc = o*2+1;
    if(y1 <= L && y2 >= R) {
        lazy[o] = true;
        sumv[o] = fbsumv[o];
    }
    else{
        pushdown(o);
        int M = (R + L) / 2;
        if(y1 <= M) Set(lc,L,M,y1,y2);
        if(y2 > M) Set(rc,M+1,R,y1,y2);
        pushup(o);
    }
    return;
}

LL query(int o,int L,int R,int y1,int y2)
{
    if(y1 <= L && y2 >= R) return sumv[o];
    LL ans = 0;
    pushdown(o);
    int M = (R + L) / 2;
    if(y1 <= M) ans += query(o*2,L,M,y1,y2);
    if(y2 > M) ans += query(o*2+1,M+1,R,y1,y2);
    pushup(o);
    return ans;
}

int main(){
    FB[0] = 1; FB[1] = 1; FB[2] = 1;
    for(int i = 3; i < 100; i++)
        FB[i] = FB[i-1] + FB[i-2];
    while(scanf("%d%d",&n,&m) != EOF)
    {
        Build(1,1,n);
        for(int i = 0; i < m; i++)
        {
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if(op == 1) Add(1,1,n,l,r);
            else if(op == 2) printf("%I64d\n",query(1,1,n,l,r));
            else if(op == 3) Set(1,1,n,l,r);
        }
    }
    return 0;
}