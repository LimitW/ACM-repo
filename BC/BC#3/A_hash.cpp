/*
 * Title:Task schedule
 * Author:LimitW
 * Date:2014.8.7
 * Source:BestCoder Round #3 A
 * Note:hash解法
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;
const int maxn = 1e5 +10;

int t[maxn];
int ok[2*maxn];
int ans[2*maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&t[i]);
        sort(t,t+n);
        memset(ok,0,sizeof(ok));
        for(i=0;i<n;i++)
        	ok[t[i]] = 1;
        int k=0;
        for(i=1;i<=t[n-1]+1;i++){
        	if(!ok[i]){
        		ans[k++]=i;
        	}
        }
        for(i=0;i<m;i++){
            int q;
            scanf("%d",&q);
            if(q>=t[n-1]+1) printf("%d\n",q);
            else{
            	int num = lower_bound(ans,ans+k,q) - ans;
            	printf("%d\n",ans[num]);
            }
        }
    }
    return 0;
}
