#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


struct node{
    int t, s, f, id;
    bool operator < (node b) const {
        return t < b.t || (t == b.t && s < b.s);
    }
}a[1010];

int ans[1010];

int main(){
    memset(ans, 0, sizeof(ans));
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].t >> a[i].s >> a[i].f;
        a[i].id = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; ++i){
        int d1 = a[i].s - a[i].f > 0 ? -1 : 1;
        for(int j = i + 1; j < n; ++j){
            int d2 = a[j].s - a[j].f > 0 ? -1 : 1;
            int dt = a[j].t - a[i].t;
            int ix = a[i].s + d1 * dt;
            if(d1 < 0 && ix < a[i].f) continue;
            else if(d1 > 0 && ix > a[i].f) continue;
            if(d1 * d2 > 0){
                if(ix == a[j].s) ++ans[a[i].id], ++ans[a[j].id];
            }
            else{
                if(d1 > 0 && d2 < 0){
                    if(a[j].s - ix >= 0 &&
                            a[j].f <= a[i].f &&
                            a[j].s - ix <= 2 * min(a[i].f - ix, a[j].s - a[j].f))
                        ++ans[a[i].id], ++ans[a[j].id];
                }
                else{
                    if(ix - a[j].s >= 0 &&
                            a[j].f >= a[i].f &&
                            ix - a[j].s <= 2 * min(ix - a[i].f, a[j].f - a[j].s))
                        ++ans[a[i].id], ++ans[a[j].id];
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << ans[i] << ' ';
    }
    return 0;
}
