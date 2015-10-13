#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int a[110];

int main(){
	memset(a, -1, sizeof(a));
	int n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	int i, j, k;
	for(i = 0; i < n; ++i) if(a[i] == 1) break;
	int ans = 0;
	for(j = i; j < n; ++j){
		++ans;
		int len = 0;
		for(k = j + 1; k < n; ++k){
			if(a[k] == 0) ++len;
			else break;
		}
		if(len > 1) j = k - 1;
		if(k == n) break;
	}
	cout << ans << '\n';
	return 0;
}

