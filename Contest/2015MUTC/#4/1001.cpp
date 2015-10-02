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

vector<int> all;

void init(){
	int vis[10];
	for(int i = 1; i <= 100000; ++i){
		memset(vis,0,sizeof(vis));
		int tmp = i , flag = 1;
		while(tmp > 0){
			int nxt = tmp % 10;
			if(vis[nxt]) { flag = 0; break; }
			vis[nxt] = 1;
			tmp /= 10;
		}
		if(flag) all.push_back(i);
	}
}

int main(){
	init();
	int T; scanf("%d",&T);
	while(T--){
		int a,b; scanf("%d%d",&a,&b);
		printf("%d\n",upper_bound(all.begin(),all.end(),b)-lower_bound(all.begin(),all.end(),a));
	}
    return 0;
}

