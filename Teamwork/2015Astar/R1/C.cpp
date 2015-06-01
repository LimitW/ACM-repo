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

int a[100010] , n;

bool check(int v){
	int tmp = a[0] - v;
	for(int i = 1; i < n; ++i) {
		if(a[i] + v <= tmp) return false;
		tmp = max(a[i] - v , tmp + 1);
	}
	return true;
}

int main(){
    int T; scanf("%d",&T);
    for(int kase = 1; kase <= T; ++kase){
        scanf("%d",&n);
        for(int i = 0; i < n; ++i){
            scanf("%d",&a[i]);
        }
        int l = 0 , r = 2e6 , ans = 0;
        while(l <= r){
        	int mid = (l + r) >> 1;
        	if(check(mid)) ans = mid , r = mid - 1;
        	else l = mid + 1;
        }
        printf("Case #%d:\n%d\n",kase,ans);
    }
    return 0;
}

