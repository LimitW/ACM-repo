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
    int n , p;
    cin >> n >> p;
    string s;
    cin >> s;
    int l = 0 , r = n - 1;
    int lmi = n - 1 , lma = 0 , rmi = n - 1 , rma = 0;
    int ans = 0;
    int cnt = 0;
    while(l <= r)
    {
        if(s[l] != s[r]){
            cnt++;
            int a = min(s[l],s[r]) , b =max(s[l],s[r]);
            int w = min(b-a,26-b+a);
            lmi = min(lmi,l); lma = max(lma,l);
            rmi = min(rmi,r); rma = max(rma,r);
            ans += w;
        }
        l++; r--;
    }
    if(cnt == 0) { cout << 0 << endl; return 0; }
    p--;
    if(p <= lmi)
    {
        ans += (lma - p);
    }
    else if(p >= lmi && p <= lma)
    {
        ans += (min(p - lmi,lma - p) * 2 + max(p - lmi,lma - p));
    }
    else if(p >= lma && p <= rmi)
    {
        ans += min(p - lmi,rma - p);
    }
    else if(p >= rmi && p <= rma)
    {
         ans += (min(p - rmi,rma - p) * 2 + max(p - rmi,rma - p));
    }
    else if(p >= rma)
    {
        ans += (p - rmi);
    }
    cout << ans << endl;
    return 0;
}