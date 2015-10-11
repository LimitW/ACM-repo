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

const int maxn = 5e6 + 10;

int A[maxn];

LL f(LL a, LL b, LL i, LL j){
    return 1ll * a * i * i + 1ll * b * j;
}

int main(){
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase){
        int n, a, b; scanf("%d%d%d", &n, &a, &b);
        for(int i = 0; i < n; ++i){
            scanf("%d", &A[i]);
        }
        int fs[3], p[3];
        if(abs(A[0]) < abs(A[1])){
            fs[2] = abs(A[0]);
            p[2] = 0;
        }
        else{
           fs[2] = abs(A[1]);
           p[2] = 1;
        }
        if(A[0] < A[1]){
            fs[1] = A[0];
            p[1] = 0;
            fs[0] = A[1];
            p[0] = 1;
        }
        else{
            fs[1] = A[1];
            p[1] = 1;
            fs[0] = A[0];
            p[0] = 0;
        }
        int nxt[3], nxtp[3];
        for(int i = 0; i < 3; ++i){
            nxt[i] = A[1^p[i]];
            nxtp[i] = 1^p[i];
        }
        nxt[2] = abs(nxt[2]);
        for(int i = 2; i < n; ++i){
            if(abs(A[i]) < nxt[2]){
                nxtp[2] = i;
                nxt[2] = abs(A[i]);
                if(nxt[2] < fs[2]){
                	swap(nxt[2], fs[2]);
                	swap(nxtp[2], p[2]);
                }
            }
            if(A[i] < nxt[1]){
                nxtp[1] = i;
                nxt[1] = A[i];
                if(nxt[1] < fs[1]){
                	swap(nxt[1], fs[1]);
                	swap(nxtp[1], p[1]);
                }
            }
            if(A[i] > nxt[0]){
                nxtp[0] = i;
                nxt[0] = A[i];
                if(nxt[0] > fs[0]){
                	swap(nxt[0], fs[0]);
                	swap(nxtp[0], p[0]);
                }
            }
        }
        vector<pii> v;
        v.clear();
        for(int i = 0; i < 3; ++i){
            v.push_back(make_pair(fs[i],p[i]));
            v.push_back(make_pair(nxt[i],nxtp[i]));
        }
        LL ans = -1ll << 62;
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < 6; ++j){
                if(v[i].second != v[j].second)
                    ans = max(ans, f(a, b, v[i].first, v[j].first));
            }
        printf("Case #%d: %I64d\n", kase, ans);
    }
    return 0;
}

