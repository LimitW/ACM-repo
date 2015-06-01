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

long long a[10010];

int main(){
    int T; scanf("%d",&T);
    for(int kase = 1; kase <= T; ++kase){
        memset(a,0,sizeof(a));
        int n;
        long long m,k;
        scanf("%d%I64d%I64d",&n,&m,&k);
        for(int i = 0; i < n; ++i) scanf("%I64d",&a[i]);
        sort(a,a+n);
        bool fail = 1;
        int cur = (int)(upper_bound(a,a+n,m) - a);
        long long val;
        if(cur == n) fail = 0;
        else if(cur == 0) {
        	if(a[0] > m) k = -1;
        	else if(a[0] == m) val = m;
        }
        else val = a[cur-1];
        for( ; k > 0; ){
            int nxt = (int)(upper_bound(a,a+n,val+k) - a);
            if(nxt == n) {
                fail = 0; break;
            }
            else if(nxt == n-1 && a[nxt] == val + k) { fail = 0; break; }
            else if(nxt == cur) break;
            else {
                val = a[nxt-1]; k--; cur = nxt;
            }
        }
        if(!fail) {
            printf("Case #%d:\n",kase);
            puts("why am I so diao?");
        }
        else {
            printf("Case #%d:\n",kase);
            puts("madan!");
        }
    }
    return 0;
}

