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
const int maxn = 1e5+3;

int x[maxn];

int check(int n){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(x[i] == 1){
            for(int j = i + 1; j < n; ++j){
                if(x[j] == x[j-1] + 1) ans++;
                else return ans;
            }
            return ans;
        }
    }
    return 0;
}

int main(){
    int n , k , sum = 0; scanf("%d%d",&n,&k);
    for(int j = 0; j < k; ++j){
        int m; scanf("%d",&m);
        for(int i = 0; i < m; ++i){
            scanf("%d",&x[i]);
        }
        sum = max(sum,check(m));
    }
    printf("%d\n",n-1-sum+n-k-sum);
    return 0;
}
