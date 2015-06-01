//============================================================================
// Name        : A.cpp
// Author      : LimitW
// Date        : 2014.11.6
// Version     :
// Copyright   : Codeforces #276 Div2 A
// Description : Implementation
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

int pow2(int n){
    int ans = 1;
    for(int i = 0; i < n; i++)
        ans *= 2;
    return ans;
}

int main(){
    int a,m;
    cin >> a >> m;
    int n  = 0 , flag = 0;
    while(pow2(n) <= m){
        if( (a*pow2(n)) % m == 0) { flag = 1; break; }
        n++;
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}