//============================================================================
// Name        : B.cpp
// Author      : LimitW
// Date        : 2014.10.31
// Version     : 
// Copyright   : 2014 Beijing Online
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

const int maxn = 1e5 + 10;
const int maxp = 1e7 + 5;

struct point
{
    double x,y;
}pnt[maxn];

bool operator < (const point &l , const point &r)
{
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}

point res[maxn];

bool mult( point sp , point ep , point op){
    return (sp.x - op.x) * (ep.y - op.y)  >= (ep.x - op.x) * (sp.y - op.y);
}

int graham(point pnt[] , int n , point res[]){
    int i , len , k = 0 , top = 1;
    sort(pnt,pnt+n);
    if(n == 0) return 0; res[0] = pnt[0];
    if(n == 1) return 1; res[1] = pnt[1];
    if(n == 2) return 2; res[2] = pnt[2];
    for(i = 2; i < n; i++)
    {
        while(top && mult(pnt[i],res[top],res[top-1])) top--;
        res[++top] = pnt[i];
    }
    len = top; res[++top] = pnt[n-2];
    for(i = n - 3; i >= 0; i--)
    {
        while(top != len && mult(pnt[i],res[top],res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int CaseNo = 1; CaseNo <= T; CaseNo++)
    {
        int n; scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&pnt[i].x,&pnt[i].h);
        }
        int nr = graham(pnt,n,res);
        int q; scanf("%d",&q);
        for(int i = 0; i < q; i++)
        {
            point Matt; scanf("%d",&Matt.x); Matt.h = 0;
            printf("Case #%d:\n%.4lf\n",CaseNo,);
        }
    }
    return 0;
}
