#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int g[102][3], dp[102][3];

int main(){
	int T; cin >> T;
	while(T--){
		memset(g, 0, sizeof(g));
		memset(dp, 0, sizeof(dp));
		int n, k; cin >> n >> k;
		string s;
		for(int i = 0; i < 3; ++i){
			cin >> s;
			for(int j = 0; j < n; ++j){
				if(s[j] == '.') g[j][i] = 1;
				else if(s[j] == 's') dp[j][i] = g[j][i] = 1;
			}
		}
		bool flag[3];
		for(int j = 0; j + 1 < n; ++j)
			for(int i = 0; i < 3; ++i){
				if(!dp[j][i]) continue;
				if(!(3 * j + 1 >= n || g[3*j+1][i])) continue;
				for(int z = 0; z < 3; ++z){
					flag[z] = 1;
					if(i + z - 1 >= 3 || i + z - 1 < 0) continue;
					for(int x = 3 * j + 1; x <= 3 * j + 4; ++x){
						flag[z] &= (x >= n || g[x][i+z-1]);
					}
					dp[j+1][i+z-1] |= flag[z];
				}
			}
		bool ans = 0;
		for(int i = 0; i < 3; ++i)
			ans |= dp[n-1][i];
		if(ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}

