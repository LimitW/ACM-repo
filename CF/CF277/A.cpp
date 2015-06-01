//============================================================================
// Name        : Template.cpp
// Author      : LimitW
// Date        :
// Version     :
// Copyright   :
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
    LL n;
    cin >> n;
    LL ans = 0;
    if(n % 2 == 0) ans = n / 2;
    else ans = (n-1)/2 - n;
    cout << ans << endl;
    return 0;
}
