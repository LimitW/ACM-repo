#include <bits/stdc++.h>

using namespace std;

int N, W, H, P;
int a[1010];

bool check(int v){
	int ha = W / v, hb = H / v;
	int cnt = 0, res = 0;
	for(int i = 0; i < N; ++i){
		cnt += (a[i] % ha ? 1 : 0) + a[i] / ha;
		res += cnt / hb;
		cnt %= hb;
	}
	return res <= P;
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%d%d%d%d", &N, &P, &W, &H);
		for(int i = 0; i < N; ++i)
			scanf("%d", a + i);
		int l = 1, r = min(W, H), ans = r;
		while(l <= r){
			int mid = l + r >> 1;
			if(check(mid)) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
    return 0;
}

