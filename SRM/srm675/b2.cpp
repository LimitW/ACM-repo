nclude <bits/stdc++.h>
using namespace std;

int d[51][51], vis[51][51];
double dp[51][51];

struct node{
	double w;
	int u, cnt;
	bool operator < (node rhs) const{
		return w > rhs.w || (w == rhs.w && cnt > rhs.cnt);
	}
};

double solve(int n, int k){
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; ++i)
	for(int j = 0; j <= k; ++j)
		dp[i][j] = 1e9;
	priority_queue<node> pq;
	dp[0][0] = 0;
	pq.push(node{0, 0, 0});
	while(!pq.empty()){
		node tp = pq.top(); pq.pop();
		if(vis[tp.u][tp.cnt]) continue;
		vis[tp.u][tp.cnt] = 1;
		for(int i = 0; i < n; ++i){
			if(dp[i][tp.cnt] > tp.w + d[tp.u][i]){
				dp[i][tp.cnt] = tp.w + d[tp.u][i];
				if(!vis[i][tp.cnt])
					pq.push(node{dp[i][tp.cnt], i, tp.cnt});
			}
			if(tp.cnt < k){
				if(dp[i][tp.cnt+1] > tp.w + 1.0 * d[tp.u][i] / 2){
					dp[i][tp.cnt+1] = tp.w + 1.0 * d[tp.u][i] / 2;
					if(!vis[i][tp.cnt+1])
						pq.push(node{dp[i][tp.cnt+1], i, tp.cnt + 1});
				}
			}
		}
	}
	double ans = 1e9;
	for(int i = 0; i <= k; ++i)
		ans = min(ans, dp[1][i]);
	return ans;
}

class ShortestPathWithMagic{
public:
	double getTime(vector <string> dist, int k){
		int n = dist.size();
		for(int i = 0; i < n; ++i){
			for(int j = 0;j < n; ++j){
				d[i][j] = dist[i][j] - '0';
			}
		}
		return solve(n, k);
	}
};
