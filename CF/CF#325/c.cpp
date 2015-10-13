#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int v[4010], d[4010], p[4010], vis[4010];

int n;

queue<int> Q;

void del1(int u){
	int tmp = v[u];
	for(int i = u + 1; i <= n; ++i){
		if(vis[i]) continue;
		p[i] -= tmp--;
		if(p[i] < 0){
			vis[i] = 1;
			Q.push(i);
		}
	}
}

void del2(int u){
	for(int i = u + 1; i <= n; ++i){
		if(vis[i]) continue;
		p[i] -= d[u];
		if(p[i] < 0){
			vis[i] = 1;
			Q.push(i);
		}
	}
}

vector<int> ans;

int main(){
	memset(vis, 0, sizeof(vis));
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> v[i] >> d[i] >> p[i];
	ans.clear();
	ans.push_back(1);
	vis[1] = 1;
	del1(1);
	int cnt = 2;
	while(cnt <= n){
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			del2(u);
		}
		while(vis[cnt]) ++cnt;
		if(cnt > n) break;
		vis[cnt] = 1;
		ans.push_back(cnt);
		del1(cnt);
		++cnt;
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	return 0;
}

