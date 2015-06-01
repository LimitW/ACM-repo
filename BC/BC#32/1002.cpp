//快速读入+set , NlogN超时，标解hash,不加快速读入依然超时…
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

const int maxn = 1e6+4;

long long read(){
    long long ans = 0 , f = 1;
    char x = getchar();
    while(!(x >= '0' && x <= '9')){
    	if(x == '-') f = -1;
    	x = getchar();
    }
    while(x >= '0' && x <= '9')
    	ans = ans * 10 + x - '0' , x = getchar();
    return ans * f;
}

long long sum[maxn];
const int hashmod = 1e6+7;
int hs[hashmod+3] , nxt[hashmod+3] , ht;
long long hv[maxn];

void insert(long long v){
	int tmp = abs(v) % hashmod;
	hv[++ht] = v; nxt[ht] = hs[tmp];
	hs[tmp] = ht;
}

bool find(long long key){
	int tmp = abs(key) % hashmod;
	for(int i = hs[tmp]; i != -1; i = nxt[i])
		if(hv[i] == key) return true;
	return false;
}

int main(){
	int T; T = read();
	for(int kase = 1; kase <= T; kase++){
		memset(hs,-1,sizeof(hs)); ht = 0; sum[0] = 0;
		int n; long long k;  n = read(); k = read();
		bool ok = false;
		for(int i = 1; i <= n; i++) {
			long long tmp; tmp = read();
			if(i & 1) sum[i] = sum[i-1] + tmp;
			else sum[i] = sum[i-1] - tmp;
		}
		insert(sum[n]);
		for(int i = n - 1; i >= 0; --i){
			if(i & 1) {
				if(find(sum[i]-k)){ ok = true; break; }
			}
			else {
				if(find(sum[i]+k)) { ok = true; break; }
			}
			insert(sum[i]);
		}
		if(ok) printf("Case #%d: Yes.\n" , kase);
		else printf("Case #%d: No.\n" , kase);
	}
	return 0;
}

