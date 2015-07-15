#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

map<int, pair<int, int> > mp;
int hs[1000010];
int a[100010];
vector<int> ans;

int main(){
    int n; cin >> n;
    int mx = 0, mx2 = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
        if (!hs[a[i]]) mp[a[i]].first = mp[a[i]].second = i + 1;
        else mp[a[i]].second = i + 1;
        ++hs[a[i]];
        mx2 = max(mx2, hs[a[i]]);
    }
    for (int i = 0; i <= mx; ++i){
        if (hs[i] == mx2)
            ans.push_back(i);
    }
    int sz = ans.size();
    int ll = 1, rr = n, len = n - 1;
    for (int i = 0; i < sz; ++i){
        if (mp[ans[i]].second - mp[ans[i]].first < len){
            ll = mp[ans[i]].first, rr = mp[ans[i]].second;
            len = mp[ans[i]].second - mp[ans[i]].first;
        }
    }
    cout << ll << ' ' << rr << '\n';
    return 0;
}
