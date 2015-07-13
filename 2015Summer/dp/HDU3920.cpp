#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double INFd = 2.0 * INF;
double dp[1024 * 1024 + 5];
double dis[21][21];
int n, sz;

struct point{
	double x, y;
}p[21];

double getdis(point a, point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double DP(int st){
	if (dp[st] != INFd) return dp[st];
	int j = 0;
	while(!((1<<j) & st)) ++j;
	for (int i = j + 1; i < n; ++i){
		if ((1 << i) & st){
			dp[st] = min(dp[st], DP(st-(1 << i)-(1 << j)) + dis[i][j]);
		}
	}
	return dp[st];
}

int main(){
	int T; scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase){
		point c; scanf("%lf%lf", &c.x, &c.y);
		scanf("%d", &n); n *= 2;
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		sz = 1 << n;
		for (int i = 0; i < sz; ++i){
			dp[i] = INFd;
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j){
				dp[(1 << i) | (1 << j)] = dis[i][j] = dis[j][i] = min(getdis(p[i], c), getdis(p[j], c)) + getdis(p[i], p[j]);
			}
		printf("Case #%d: %.2lf\n",kase,DP(sz - 1));
	}
	return 0;
}
