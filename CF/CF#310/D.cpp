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
const int maxn = 2e5+4;

struct island{
    LL l,r;
    bool operator < (island b) const {
        return r < b.r || (r == b.r && l < b.l);
    }
}p[maxn];
pair<pair<LL,LL>,int> e[maxn];
int ans[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i){
        scanf("%I64d%I64d",&p[i].l,&p[i].r);
    }
    sort(p,p+n);
    for(int i = 1; i < n; ++i){
        e[i] = make_pair(make_pair(p[i].r-p[i-1].l,p[i].l-p[i-1].r),i-1);
    }
    sort(e+1,e+n);
    set<pair<LL,LL> > st;
    for(int i = 0; i < m; ++i){
        LL tmp; scanf("%I64d",&tmp);
        st.insert(make_pair(tmp,i+1));
    }
    bool fail = 0;
    for(int i = 1; i < n; ++i){
        set< pair<LL,LL> >::iterator u = st.lower_bound(make_pair(e[i].first.second,0));
        if(u == st.end() || u->first > e[i].first.first) { fail = 1; break; }
        else {
            ans[e[i].second] = u->second;
            st.erase(u);
        }
    }
    if(fail) puts("No");
    else {
        puts("Yes");
        for(int i = 0; i < n-1; ++i)
            printf("%d%c",ans[i],i==n-2?'\n':' ');
    }
    return 0;
}
