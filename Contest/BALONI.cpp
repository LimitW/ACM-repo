#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 3;

int a[maxn], hs[maxn];

int main(){
	memset(hs, 0, sizeof(hs));
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if(hs[a[i]+1]) --hs[a[i]+1], ++hs[a[i]];
		else ++hs[a[i]], ++ans;
	}
	cout << ans << '\n';
	return 0;
}

