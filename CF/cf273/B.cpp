//============================================================================
// Name        : B.cpp
// Author      : LimitW
// Date        : 2014.10.17
// Version     :
// Copyright   : CF 273 B
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

const int INF = 0x3f3f3f3f;

int main(){
    LL n,m;
    cin >> n >> m;
    if(n == m){ cout << "0 0" <<endl; return 0;}
    LL res = n - m;
    LL ans2 = (n - m)*(n-m+1)/2;
    LL ans1 = 0;
    LL k = res / m;
    ans1 = (k+2)*(k+1)*(res - k*m)/2 + (k+1)*k*(m-res+k*m)/2;
    cout << ans1 <<' '<<ans2<< endl;
    return 0;
}
