#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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

const int INF = 0x3f3f3f3f;
int a[100010];

int main(){
    int T; scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        long long ans = 0;
        int n,k; scanf("%d%d",&n,&k);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        a[n] = a[n-1];
        for(int i = 0 , j = 1; j <= n && i < n ; )
        {
            if(a[j] - a[i] <= k)
            {
                if(j == n - 1) { ans += (long long)(j-i); i++; }
                else j++;
            }
            else
            {
                ans += (long long)(j-i-1);
                i++;
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}