#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

long long a[N + 1];
bool h[10];

int main(){
	for(int i = 1; i <= N; ++i){
		long long j = 1ll, cur, tmp;
		int cnt = 0;
		memset(h, 0 ,sizeof(h));
		while(cnt < 10){
			cur = tmp = j * i;
			while(tmp){
				if(!h[tmp % 10]) h[tmp % 10] = 1, ++cnt;
				tmp /= 10;
			}
			++j;
		}
		a[i] = cur;
	}
	int T; cin >> T;
	for(int kase = 1; kase <= T; ++kase){
		int n; cin >> n;
		if(n == 0) printf("Case #%d: INSOMNIA\n", kase);
		else printf("Case #%d: %lld\n", kase, a[n]);
	}
    return 0;
}

