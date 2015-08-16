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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const LL mod = 3221225473LL;
const int maxn = 3e6 + 3;
//const int maxm = maxn * maxn;

int a[maxn], w[maxn];
bool tag[maxn], vis[maxn];

void pre(){
    memset(tag, 0, sizeof(tag));
    for(int i = 2; i < 3000001; ++i){
        if(!tag[i]){
            for(int j = 2; j * i < 3000001; ++j)
                tag[i * j] = 1;
        }
    }
}

void divide(int x){
    for(int i = 2; i * i <= x; ++i){
        if(tag[i]) continue;
        if(x % i == 0){
            int num = 0;
            while(x % i == 0){
                x /= i, ++num;
            }
            w[i] = max(w[i], num);
        }
    }
    w[x] = max(w[x],1);
}

LL quickpow(LL a, LL b){
    LL ans = 1, tmp = a;
    while(b){
        if(b & 1) ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ans;
}

int main(){
    linear_pre();
    int T, n; scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        memset(vis, 0, sizeof(vis));
        memset(w, 0, sizeof(w));
        int len, x;
        for(int i = 1; i <= n; ++i){
            if(!vis[i]){
                len = 0, x = i;
                while(!vis[x]){
                    vis[x] = 1, ++len, x = a[x];
                }
                divide(len);
            }
        }
        LL ans = 1ll;
        for(int i = 2; i <= n; ++i){
            if(w[i]){
                ans *= quickpow(i,w[i]);
                ans %= mod;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
