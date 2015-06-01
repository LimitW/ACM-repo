//============================================================================
// Name        : B.cpp
// Author      : LimitW
// Date        : 2014.11.6
// Version     :
// Copyright   : Codeforces #276 Div2 B
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
pii mine[1010];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> mine[i].first >> mine[i].second;
    int x1 = INF , x2 = -INF;
    int y1 = INF , y2 = -INF;
    for(int i = 0; i < n; i++){
        x1 = min(x1,mine[i].first);
        x2 = max(x2,mine[i].first);
        y2 = max(y2,mine[i].second);
        y1 = min(y1,mine[i].second);
    }
    int l = max(x2-x1,y2-y1);
    LL ans = 1;
    ans *= (LL)(l) * (LL)(l);
    printf("%I64d\n",ans);
    return 0;
}