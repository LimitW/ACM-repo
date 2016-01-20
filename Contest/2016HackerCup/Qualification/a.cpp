#include <bits/stdc++.h>

using namespace std;

struct point {
	long long x, y;
}p[2010];

long long dist(point a, point b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

map<long long, int> mp[2010];

int main(){
	int T; cin >> T;
	for(int kase = 1; kase <= T; ++kase){
		int N; cin >> N;
		for(int i = 0; i < N; ++i)
			mp[i].clear();
		for(int i = 0; i < N; ++i)
			cin >> p[i].x >> p[i].y;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j){
				if(i == j) continue;
				long long x = dist(p[i], p[j]);
				mp[i][x]++;
			}
		long long ans = 0;
		for(int i = 0; i < N; ++i){
			for(auto v : mp[i]){
				ans += (v.second * (v.second - 1) / 2);
			}
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
	return 0;
}
