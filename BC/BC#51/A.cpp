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
s
#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 3;
//const int maxm = maxn * maxn;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        if(n == 2) { puts("1"); continue; }
        if(n == 3) { puts("2"); continue; }
        if(n == 4) { puts("2"); continue; }
        bool flag = 0;
        for(int i = 2; i * i <= n; ++i){
            if(n % i == 0) { flag = 1; break; }
        }
        printf("%d\n",flag ? 0 : n - 1);
    }s
    return 0;
}
