#include <bits/stdc++.h>

using namespace std;

long long ans[5], p[5];
long long s[50];
long long res;

int main(){
	memset(ans, 0, sizeof(ans));
	int n; cin >> n;
	res = 0;
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	for(int i = 0; i < 5; ++i){
		cin >> p[i];
	}
	for(int i = 0; i < n; ++i){
		res += s[i];
		for(int j = 4; j >= 0; --j){
			long long x = res / p[j];
			ans[j] += x;
			res -= x * p[j];
		}
	}
	for(int i = 0; i < 5; ++i)
		cout << ans[i] << ' ';
	cout << '\n' << res << '\n';
	return 0;
}
