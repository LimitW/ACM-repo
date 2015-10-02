#include <iostream>
#include <iomanip>
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
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long

const int maxn = 1e7;

int prime[maxn+5];

int main(){
	freopen("homework.txt","r",stdin);
	freopen("A.txt","w",stdout);
	memset(prime,0,sizeof(prime));
    for(int i = 2; i <= maxn; i++){
        if(prime[i]) continue;
        for(int j = i; j <= maxn; j += i) prime[j]++;
    }
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; kase++)
	{
		int a,b,k; scanf("%d%d%d",&a,&b,&k);
		int ans = 0;
		for(int i = a; i <= b; i++)
		{
			if(prime[i] == k) ans++;
		}
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}
