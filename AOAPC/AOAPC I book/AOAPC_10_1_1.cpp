//============================================================================
// Name        : AOAPC_10_1_1.cpp
// Author      : LimitW
// Date        : 2014.12.10
// Version     :
// Copyright   : AOAPC I
// Description : gcd && lcm
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

int gcd(int a,int b){
    return b  == 0 ? a : gcd(b , a % b);
}

int lcm(int a,int b){
    return a / gcd(a,b) * b;
}

int x[10000+10];
int main(){
    int n; scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&x[i]);
    x[2] /= gcd(x[2],x[1]);
    for(int i  = 3; i <= n && x[2] != 1; i++)
        x[2] /= gcd(x[i],x[2]);
    if(x[2] == 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}
