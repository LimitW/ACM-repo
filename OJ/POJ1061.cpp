//============================================================================
// Name        : POJ1061.cpp
// Author      : LimitW
// Date        : 2014.12.10
// Version     :
// Copyright   : POJ1061
// Description : Extended gcd
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

LL gcd(LL a,LL b){
    return b == 0 ? a : gcd(b,a%b);
}
//ax + by = gcd(a,b)
void exgcd(LL a,LL b,LL& d,LL& x,LL& y){
    if(!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}
// x + m*t - y - n*t = p*L -> (x-y)+(m-n)*t=p*L -> (m-n)*t-L*p=y-x
// a = m - n; b = -L; c = y - x

int main(){
    LL x,y,m,n,L;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
    LL a = m - n ,  b = -L , c = y - x;
    LL d,t,p;
    exgcd(a,b,d,t,p);
    if(c % d != 0) { printf("Impossible\n"); return 0; }
    t *= c / d; p *= c / d;
    LL a1 = a / gcd(a,b) , b1 = b / gcd(a,b);
    LL ans = t;
    while(t < 0){
        if(b1 > 0) t += b1;
        else t -= b1;
    }
    while(t >= 0){
        if(b1 > 0) { ans = t; t -= b1; }
        else { ans = t;  t += b1; }
    }
    printf("%lld\n",ans);
    return 0;
}