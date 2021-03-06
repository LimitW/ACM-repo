#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n;
pair<int,int> a[110];
int vis[10010], cnt[110];

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second < b.second || (a.second == b.second && a.first < b.first);
}

bool check(int v){
	memset(vis, -1, sizeof(vis));
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		for(int j = a[i].first; j < a[i].second; ++j){
			if(cnt == v) break;
			if(vis[j] == -1) ++cnt, vis[j] = i;
		}
		if(cnt < v) return 0;
	}
	return 1;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n, cmp);
	int l = 0, r = 10000, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << n * ans << '\n';
	return 0;
}

