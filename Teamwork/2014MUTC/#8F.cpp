//============================================================================
// Name        : F.cpp
// Author      : LimitW
// Date        :
// Version     :
// Copyright   : 2014 MUTC #8 F
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

int main(){
    LL h,a,b,k; int t = 0;
    while(cin >> h >> a >> b >> k && ! (h == 0 && a == 0 && b == 0 && k == 0))
    {
        bool flag = false;
        if(a >= h) flag = true;
        else if( k * a - (k - 1) * b >= h) flag = true;
        else if( (k + 1) * b < k * a) flag = true;
        if(flag) printf("Case #%d: YES\n",++t);
        else printf("Case #%d: NO\n", ++t);
    }
    return 0;
}
