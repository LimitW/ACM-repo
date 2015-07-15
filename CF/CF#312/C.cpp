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

const int INF = 0x3f3f3f3fLL;

int n;
int a[100010];

int step[100005], cnt[100005], vis[100005];
queue<pii> q;

int main(){
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		mx = max(mx, a[i]);
		q.push(make_pair(a[i], 0));
		while (!q.empty()){
			pii tp = q.front();
			q.pop();
			if (tp.first > 100000 || tp.first < 1) continue;
			if (vis[tp.first] == i+1) continue;
			vis[tp.first] = i+1;
			cnt[tp.first]++;
			step[tp.first] += tp.second;
			q.push(make_pair(tp.first / 2, tp.second + 1));
			q.push(make_pair(tp.first * 2, tp.second + 1));
		}
	}
	int ans = INF;
	for (int i = 1; i <= mx; ++i){
		if (cnt[i] == n){
			ans = min(ans, step[i]);
		}
	}
	cout << ans << '\n';
	return 0;
}
