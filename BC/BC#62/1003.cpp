#include <bits/stdc++.h>

using namespace std;

int hs[10000001];
int a[20000000];

long long n, q, seed;

int rand(int l, int r){
	static long long mo=1e9+7, g=78125;
	return l+((seed*=g)%=mo)%(r-l+1);
}

int main(){
	int T; cin >> T;
	while(T--){
		memset(hs, 0, sizeof(hs));
		cin >> n >> q >> seed;
		int sum = rand(q, 10000000);
		for(int i = 1; i <= n; ++i){
			a[i] = rand(0, sum / (n - i + 1));
			sum -= a[i];
		}
		a[rand(1, n)] += sum;
		int mx = 0;
		for(int i = 1; i <= n; ++i){
			++hs[a[i]];
			mx = max(mx, a[i]);
		}
		int i, j, cnt = 0, ans = 0;
		for(i = mx; i > 0; --i){
			while(hs[i] && q){
				hs[i]--, hs[i-1]++, q--;
			}
			if(!q) break;
		}
		for(j = n, ans = 0; j >= 1; --j){
			if(a[j] < i)
				ans ^= (a[j] + j);
			else if(a[j] >= i && cnt < hs[i])
				ans ^= (i + j), ++cnt;
			else
				ans ^= (i + j - 1);
		}
		cout << ans << '\n';
 	}
	return 0;
}

