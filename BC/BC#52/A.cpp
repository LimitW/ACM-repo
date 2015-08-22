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
const int mod = 1e9 + 7;
const int maxn = 1 << 16;
//const int maxm = maxn * maxn;

int main(){
    int x,y,w,n;
    while(~scanf("%d%d%d%d",&x,&y,&w,&n)){
        int t = 0, cnt = 1, opent = 0;
        while(true){
            if(cnt == n){
                printf("%d\n",t);
                break;
            }
            if(opent != 0 && opent % w == 0) ++cnt;
            if(cnt == n){
                printf("%d\n",t);
                break;
            }
            if(opent == x){
                opent = 0, t += y, ++cnt;
            }
            else ++opent, ++t;
        }
    }
    return 0;
}

