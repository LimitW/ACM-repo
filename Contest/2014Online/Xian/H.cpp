/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
const int  maxn = 1e6+10;

int a[maxn];
int rank[maxn];
bool f[maxn];
int b[maxn];

int fun(int x){
    int ans = 1;
    while(ans <= x){
        ans *= 2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n;
	while(~scanf("%d",&n)){
	    memset(f,0,sizeof(f));
        for(int i = 0; i <= n; i++){
            scanf("%d",&a[i]);
            rank[a[i]] = i;
        }
        for(int i = n; i >= 0; i--){
            if(!f[i]){
                int ans = fun(i);
                if(ans - i  - 1 >= 0){
                    b[rank[i]] = ans - 1 - i;
                    b[rank[ans-i-1]] = i;
                    f[i] = 1;
                    f[ans-1-i] = 1;
                }
            }
        }
        ll t = 0;
        for(int i = 0; i <= n; ++i)
            t += (ll) a[i]^b[i];
        printf("%I64d\n",t);
        for(int i = 0; i <= n; i++)
            i==n ? printf("%d\n",b[i]):printf("%d ",b[i]);
	}
    return 0;
}