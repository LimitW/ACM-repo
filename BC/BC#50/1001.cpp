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
const int maxn = 30 + 3;
const int maxm = 100 + 3;

int a[10010];

int main(){
    int n;
    while(~scanf("%d",&n)){
        int sum = 0;
        memset(a,0,sizeof(a));
        for(int i = 0; i < n; ++i){
            int tmp; scanf("%d",&tmp);
            ++a[tmp]; ++sum;
        }
        bool flag = 0;
        for(int i = 1; i < 10000; ++i){
            if(a[i] > sum - a[i]){
                printf("%d\n",i);
                flag = 1; break;
            }
        }
        if(!flag) puts("-1");
    }
    return 0;
}
