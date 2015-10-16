#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

#define LL long long
#define pii pair<int,int>

int bits[33];

int main(){
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase){
        int n, s1, s2; scanf("%d%d%d", &n, &s1, &s2);
        LL tmp = n;
        int cnt = 0, p = 0;
        while(tmp > 0){
            if(tmp & 1) ++cnt;
            bits[p++] = tmp & 1;
            tmp >>= 1;
        }
        LL ans = 1ll * n + 1;
        if(!(n & 1) && cnt == s2){
            if(ans & 2) ++ans;
            else{
                --ans;
                int flag = -1;
                for(int j = 0; j < p; ++j){
                    if(bits[j]) { flag = j; break; }
                }
                ans += 1 << flag;
            }
        }
        tmp = ans, cnt = 0;
        while(tmp > 0){
            if(tmp & 1) ++cnt;
            tmp >>= 1;
        }
        for(int j = 0; cnt < s1 && j < 32; ++j){
            if(!(ans & (1ll << j))) ans ^= (1ll << j), ++cnt;
        }
        printf("Case #%d: %I64d\n", kase, ans);
    }
    return 0;
}
