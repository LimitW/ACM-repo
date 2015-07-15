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

struct aa{
    int v, x;
    bool operator < (aa b) const{
        return x < b.x;
    }
}a[110];

int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i].x >> a[i].v;
    }
    sort(a, a + n);
    int tmp = -1;
    for (int i = 0; i < n; ++i){
        if (a[i].x > 0){
            tmp = i;
            break;
        }
    }
    int ans = 0;
    if (tmp == 0) ans = a[0].v;
    else if (tmp == -1) ans = a[n - 1].v;
    else{
        int i, j;
        for (i = tmp - 1, j = tmp; i >= 0 && j < n; --i, ++j){
            ans += a[i].v;
            ans += a[j].v;
        }
        if (j < n) ans += a[j].v;
        else if (i >= 0) ans += a[i].v;
    }
    cout << ans << '\n';
    return 0;
}
