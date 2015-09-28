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
const double pi = acos(-1.0);
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const int maxn = (1 << 10) + 3;

int a[100010], ans[100010];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ans[n-1] = 0;
    int mx = a[n-1];
    for(int i = n - 2; i >= 0; --i){
        if(a[i] > mx) ans[i] = 0;
        else ans[i] = mx - a[i] + 1;
        mx = max(a[i], mx);
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    return 0;
}
