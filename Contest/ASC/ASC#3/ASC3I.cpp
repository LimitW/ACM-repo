//============================================================================
// Name        : I.cpp
// Author      : LimitW
// Date        : 2014.11.2
// Version     :
// Copyright   : ASC #3 I
// Description : Simpson Integral
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

const long double eps = 1e-5;

long double r1,r2;

long double f(long double x)
{
    return sqrt((r1*r1-x*x) * (r2*r2-x*x));
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        long double s = 0;
        scanf("%Lf%Lf",&r1,&r2);
        if(r1 > r2) swap(r1,r2);
        int n = (int) (r1/eps);
        long double h = r1 / n / 2;
        s += f(0) + f(r1);
        for(int i = 1; i < 2*n; i++)
        {
            if( i & 1) s += 4*f(i*h);
            else s += 2*f(i*h);
        }
        s /= 6*n;
        s *= 8*r1;
        printf("%.4Lf\n",s);
        printf("\n");
    }
    return 0;
}