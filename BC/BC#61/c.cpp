#include <bits/stdc++.h>

using namespace std;

int lowbit_pos(int x){
	x = x & -x;
	int p = 1;
	while(!(x & 1)) ++p, x >>= 1;
	return p;
}

int main(){
	long long n;
	while(cin >> n){
		unsigned long long p = 1ull;
		int dep = 0;
		for(; p <= n; p <<= 1) ++dep;
		p = (p >> 1) - (p - 1 - n);
		int dep2 = log2(p) + 1;
		int ans = max(dep - 2, dep2);
		ans += (dep - lowbit_pos(p));
		cout << ans << '\n';
	}
	return 0;
}

