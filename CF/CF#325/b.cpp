#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int a[52][2], b[52];
int sum[52][2];

int main(){
	memset(sum, 0, sizeof(sum));
	int n; cin >> n;
	for(int j = 0; j < 2; ++j)
		for(int i = 1; i < n; ++i){
			cin >> a[i][j];
			sum[i][j] = sum[i-1][j] + a[i][j];
		}
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	int ans = INF;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j){
			if(j == i) continue;
			int cnt = 0;
			cnt += b[i] + b[j];
			cnt += sum[i][0] + sum[j][0];
			cnt += 2 * sum[n-1][1] - sum[j][1] - sum[i][1];
			ans = min(ans, cnt);
		}
	cout << ans << '\n';
	return 0;
}

