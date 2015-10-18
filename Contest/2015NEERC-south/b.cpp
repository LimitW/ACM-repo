#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

pair<int, int> p[4010];
int vb[4010], f[4010][4010];

int main(){
	memset(f, 0, sizeof(f));
	int n; cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> p[i].first >> p[i].second;
		if(p[i].first > p[i].second) swap(p[i].first, p[i].second);
		vb[i] = p[i].second;
	}
	sort(vb, vb + n);
	sort(p, p + n);
	int y = unique(vb, vb + n) - vb;
	for(int i = 0; i < y; ++i)
		for(int j = n - 1; j >= 0; --j)
			f[i][j] = f[i][j+1] + (p[j].second >= vb[i]);
	long long S = 0, nx, ny;
	for(int i = 0; i < n; ++i)
		for(int j = y - 1; j >= 0; --j){
			long long cx = p[i].first, cy = vb[j];
			if(cx * cy * f[j][i] > S){
				S = cx * cy * f[j][i];
				nx = cx, ny = cy;
			}
		}
	printf("%I64d\n%I64d %I64d\n", S, nx, ny);
	return 0;
}

