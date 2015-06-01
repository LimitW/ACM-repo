//============================================================================
// Name        : AOAPC_10_1_3.cpp
// Author      : LimitW
// Date        : 2014.12.10
// Version     :
// Copyright   : AOAPC I
// Description : Extended Euclidean Algorithm
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

//ax + by = gcd(a,b)
int a,b,d,x,y;
void gcd(int a,int b,int& d,int& x,int& y){
    if(!b) { d = a; x = 1; y = 0; }
    else { gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

int main(){
    int c,x1,x2,y1,y2;
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
    gcd(a,b,d,x,y);
    int ans = 0;
    if(c % d == 0)
    {
        x *= -c / d; y *= -c / d;
        for(int i = 1 ; ; i++){
            int cx = x * i , cy = y * i;
            int ok = 0;
            if(cx >= x1 && cx <= x2 && cy >= y1 && cy <= y2) { ans++; ok = 1; }
            if(-cx >= x1 && -cx <= x2 && -cy >= y1 && -cy <= y2) { ans++; ok = 1; }
            if(!ok) break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
6 15 -9
-100 100 -100 100
 */